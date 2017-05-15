#include "VisionComponent.h"

std::thread t;

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

	//cv::Mat edges;
	cv::namedWindow("edges", 1);
	for (;;)
	{
		cv::Mat frame;
		cap >> frame; // get a new frame from camera
		//cvtColor(frame, edges, CV_BGR2GRAY);
		//GaussianBlur(edges, edges, cv::Size(7, 7), 1.5, 1.5);
		//Canny(frame, edges, 0, 30, 3);
		imshow("edges", frame);
		cvWaitKey(1);
	}
	// the camera will be deinitialized automatically in VideoCapture destructor
	return;
}
