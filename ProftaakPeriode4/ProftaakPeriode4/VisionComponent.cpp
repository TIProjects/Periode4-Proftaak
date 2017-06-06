#include "VisionComponent.h"

/*
* Constructor of VisionComponent
* 
* Initialise a camera connected to the computer
* check if camera is initialized
*/
VisionComponent::VisionComponent(int laneAmount) : Component(VISION_COMPONENT)
{
	_position = cv::Point2f(_imageSize / 2);

	_heightDiv = 4;
	_widthDiv = laneAmount;

	_jumpBound = (_imageSize.height / _heightDiv);
	_crouchBound = (_imageSize.height / _heightDiv) * (_heightDiv - 1);

	_leftBound = (_imageSize.width / _widthDiv);
	_rightBound = (_imageSize.width / _widthDiv) * (_widthDiv - 1);

	_laneCount = laneAmount;

	_visionThread = std::thread(&VisionComponent::CameraUpdate, this);
	_visionThread.detach();
}


VisionComponent::~VisionComponent()
{
}

/*
* Update method of this component
* is called every update of the game
* @param float deltaTime: elapsed time between frames
*/
void VisionComponent::CameraUpdate()
{
	cv::VideoCapture cap(0); // open the default camera
	if (!cap.isOpened())  // check if we succeeded
		return;
	//loop for capturing images from camera and detecting
	while (!_terminateThread)
	{

		cv::Mat img1;
		cv::Mat img2;
		cv::Mat diff;

		cap >> img1;
		cap >> img2;

		cvtColor(img1, img1, CV_BGR2GRAY);
		cvtColor(img2, img2, CV_BGR2GRAY);

		//difference between img1 and 2
		cv::absdiff(img1, img2, diff);

		//flip image
		cv::flip(diff, diff, 1);

		//resize the difference
		cv::resize(diff, diff, _imageSize);

		//blur the difference
		cv::medianBlur(diff, _src_gray, 5);

		//calculate 
		CalculatePosition();

		cv::waitKey(1);
	}
	// the camera will be deinitialized automatically in VideoCapture destructor
}

void VisionComponent::CalculatePosition()
{
	//output after applied treshold
	cv::Mat threshold_output;

	//contours of all detected motions
	std::vector<std::vector<cv::Point> > contours;
	std::vector<std::vector<cv::Point> > filteredContours;

	// Detect edges using Threshold
	cv::threshold(_src_gray, threshold_output, _thresh, 255, cv::THRESH_BINARY);

	// Find contours
	cv::findContours(threshold_output, contours, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE);

	//filter contour area
	// Draw contours
	cv::Mat drawing = cv::Mat::zeros(threshold_output.size(), CV_8UC3);
	for (int i = 0; i < contours.size(); i++)
	{
		//filter contour sizes
		if (contours[i].size() < 30|| contours[i].size() > 60)
		{
			continue;
		}
		
		//draw and fill contours in mat drawing vector
		filteredContours.push_back((contours[i]));
		cv::drawContours(drawing, contours, i, cv::Scalar(255, 255, 255), CV_FILLED, 8, std::vector<cv::Vec4i>(), 0, cv::Point());
	}

	if (filteredContours.size() != 0)
	{
		// Get the moments
		std::vector<cv::Moments> mu(filteredContours.size());
		for (int i = 0; i < filteredContours.size(); i++)
		{
			mu[i] = moments(filteredContours[i], false);
		}

		//  Get the mass centers:
		std::vector<cv::Point2f> mc(filteredContours.size());
		for (int i = 0; i < filteredContours.size(); i++)
		{
			mc[i] = cv::Point2f((float)mu[i].m10 / (float)mu[i].m00, (float)mu[i].m01 / (float)mu[i].m00);
			cv::circle(drawing, mc[i], _radius, cv::Scalar(255, 255, 0), CV_FILLED, 8, 0);
		}
		
		//calculate average between center points
		int avrg = 0;
		cv::Point2f point = cv::Point2f(0, 0);
		for (int i = 0; i < mc.size(); i++)
		{
			//check if point is an undefined value
			if (isnan(mc[i].x))
				continue;
			point.x += mc[i].x;
			point.y += mc[i].y;
			avrg++;
		}
		point.x /= avrg;
		point.y /= avrg;

		_position = point;
	}
	
		
	if (_debugMotion)
	{
		cv::Scalar color = cv::Scalar(0, 255, 0);
		//draw debug lines
		//jump
		cv::line(drawing, cv::Point(0, _jumpBound), cv::Point(_imageSize.width, _jumpBound), color, 1);
		//crouch
		cv::line(drawing, cv::Point(0, _crouchBound), cv::Point(_imageSize.width, _crouchBound), color, 1);
		//left
		cv::line(drawing, cv::Point(_leftBound, 0), cv::Point(_leftBound, _imageSize.height), color, 1);
		//right
		cv::line(drawing, cv::Point(_rightBound, 0), cv::Point(_rightBound, _imageSize.height), color, 1);

		//draw position of circle
		cv::circle(drawing, _position, _radius, cv::Scalar(0, 0, 255), CV_FILLED, 8, 0);
		imshow("drawing", drawing);
		//imshow("tresh", threshold_output);
	}
}

void VisionComponent::GetControls(int *lane, bool *crouch, bool *jump)
{
	if (_position.x < _leftBound)
	{
		*lane = 0;
	}
	else if (_position.x > _rightBound)
	{
		*lane = _laneCount - 1;
	}
	else 
	{
		*lane = (int)ceil(_laneCount / 2);
	}

	if (_position.y < _jumpBound)
	{
		*jump = true;
	}
	else
	{
		*jump = false;
	}

	if (_position.y > _crouchBound)
	{
		*crouch = true;
	}
	else
	{
		*crouch = false; 
	}
}

void VisionComponent::stopVisionThread()
{
	_terminateThread = true;
	cv::destroyAllWindows();
}
