#include "VisionComponent.h"

std::thread t;

cv::Mat src; cv::Mat src_gray;
int thresh = 50;
int max_thresh = 255;

void thresh_callback(int, void*);

/*
* Constructor of VisionComponent
* 
* Initialise a camera connected to the computer
* check if camera is initialized
*/
VisionComponent::VisionComponent() : Component(VISION_COMPONENT)
{

	t = std::thread(&VisionComponent::CameraUpdate, this);
	t.detach();
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
	for (;;)
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
		//blur the difference
		cv::medianBlur(diff, src_gray, 5);
		//resize the difference
		cv::resize(diff, diff, cv::Size(0, 0), 0.2, 0.2);
		//threshold the difference
		cv::threshold(diff, diff, 50, 255, CV_THRESH_BINARY);
		//calculate 
		thresh_callback(0, 0);

		cv::waitKey(1);
	}
	// the camera will be deinitialized automatically in VideoCapture destructor
}


/** @function thresh_callback */
void thresh_callback(int, void*)
{
	cv::Mat threshold_output;
	std::vector<std::vector<cv::Point> > contours;

	/// Detect edges using Threshold
	cv::threshold(src_gray, threshold_output, thresh, 255, cv::THRESH_BINARY);

	/// Find contours
	cv::findContours(threshold_output, contours, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE);

	/// Find the convex hull object for each contour
	std::vector<std::vector<cv::Point> >hull(contours.size());
	for (int i = 0; i < contours.size(); i++)
	{
		cv::convexHull(cv::Mat(contours[i]), hull[i], false);
	}

	//filter contour area
	// Draw contours + hull results
	cv::Mat drawing = cv::Mat::zeros(threshold_output.size(), CV_8UC3);
	for (int i = 0; i < contours.size(); i++)
	{
		//filter contour sizes
		if (contours[i].size() < 70 || contours[i].size() > 200)
		{
			continue;
		}
		//draw and fill contours in mat
		cv::drawContours(drawing, hull, i, cv::Scalar(255, 255, 255), CV_FILLED, 8, std::vector<cv::Vec4i>(), 0, cv::Point());
		cv::rectangle(drawing, cv::boundingRect(contours[i]), cv::Scalar(255, 0, 0), 1, 8, 0);
	}

	imshow("drawing", drawing);
}
