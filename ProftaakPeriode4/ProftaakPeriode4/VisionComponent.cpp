#include "VisionComponent.h"

std::thread t;

cv::Mat src; cv::Mat src_gray;
int thresh = 100;
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

	//cv::SimpleBlobDetector::Params params;
	//
	//////// Thresholds
	////params.minThreshold = 100;
	////params.maxThreshold = 200;

	//// Filter by Area.
	//params.filterByArea = false;
	//params.minArea = 2000;

	//// Filter by Circularity
	//params.filterByCircularity = true;
	//params.minCircularity = 0.0;

	//// Filter by Convexity
	//params.filterByConvexity = true;
	//params.minConvexity = 0.8;

	//// Filter by Inertia
	//params.filterByInertia = true;
	//params.minInertiaRatio = 0.20;

	//cv::Ptr<cv::SimpleBlobDetector> detector = cv::SimpleBlobDetector::create(params); //creates smart pointer
	//std::vector<cv::KeyPoint> keypoints; //storage for blob keybpoints

	cv::Mat frame;
	cv::Mat edges;

	//frame = cv::imread("D:/Users/Joey/Desktop/pics/bodys.PNG", CV_LOAD_IMAGE_COLOR);

	cv::namedWindow("edges", 1);
	//loop for capturing images from camera and detecting
	for (;;)
	{
		cap >> frame; // get a new frame from camera
	
		//cvtColor(frame, edges, CV_BGR2GRAY);
		//GaussianBlur(edges, edges, cv::Size(7, 7), 1.5, 1.5);

		////values between 90 and 180
		//cv::threshold(edges, edges, 100, 170, CV_THRESH_BINARY);

		//detector->detect(edges, keypoints); //detect blobs

		//drawKeypoints(edges, keypoints, edges, cv::Scalar(0, 0, 255), cv::DrawMatchesFlags::DRAW_RICH_KEYPOINTS); //draw blobs

		/// Convert image to gray and blur it
		cv::cvtColor(frame, src_gray, CV_BGR2GRAY);
		blur(src_gray, src_gray, cv::Size(10, 10));

		/// Create Window
		char* source_window = "Source";
		cv::namedWindow(source_window, CV_WINDOW_AUTOSIZE);
		cv::imshow(source_window, frame);

		cv::createTrackbar(" Threshold:", "Source", &thresh, max_thresh, thresh_callback);
		thresh_callback(0, 0);

		cv::waitKey(1);
	}
	// the camera will be deinitialized automatically in VideoCapture destructor
}


/** @function thresh_callback */
void thresh_callback(int, void*)
{
	cv::Mat src_copy = src.clone();
	cv::Mat threshold_output;
	std::vector<std::vector<cv::Point> > contours;
	std::vector<cv::Vec4i> hierarchy;

	/// Detect edges using Threshold
	cv::threshold(src_gray, threshold_output, thresh, 255, cv::THRESH_BINARY);

	/// Find contours
	cv::findContours(threshold_output, contours, /*hierarchy,*/ CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE/*, cv::Point(0, 0)*/);

	/// Find the convex hull object for each contour
	std::vector<std::vector<cv::Point> >hull(contours.size());
	for (int i = 0; i < contours.size(); i++)
	{
		cv::convexHull(cv::Mat(contours[i]), hull[i], false);
	}

	/// Draw contours + hull results
	cv::Mat drawing = cv::Mat::zeros(threshold_output.size(), CV_8UC3);
	for (int i = 0; i< contours.size(); i++)
	{
		cv::drawContours(threshold_output, hull, i, cv::Scalar(255,255,255), 1, 8, std::vector<cv::Vec4i>(), 0, cv::Point());
	}

	/// Show in a window
	cv::namedWindow("Hull demo", CV_WINDOW_AUTOSIZE);
	imshow("Hull demo", threshold_output);
}
