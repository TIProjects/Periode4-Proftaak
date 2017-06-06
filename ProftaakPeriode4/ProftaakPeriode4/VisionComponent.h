#pragma once
#include "Component.h"
#include <opencv2\opencv.hpp>
#include <iostream>
#include <string>
#include "Input.h"
#include <thread>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <stdio.h>
#include <stdlib.h>



class VisionComponent : public Component
{
public:
	explicit VisionComponent(int laneAmount);
	~VisionComponent();
	//void Update(float deltaTime) override;
	
	/*
	*Captures video, applies filters and detects motion
	*/
	void CameraUpdate();

	/*
	*Calculates position from the largest motion detected, updates _position to this value
	*/
	void CalculatePosition();

	/*
	*returns booleans for crouching jumping and int for lanes
	*/
	void GetControls(int *lane, bool *crouch, bool *jump);

	/*
	* stops the vision thread
	*/
	void stopVisionThread();

	/*
	*Position of the point based on motion detection
	*/
	cv::Point2f _position;

	/*
	*Boolean to draw debug lines for camera
	*/
	bool _debugMotion = true;

	/*
	*Size of the captured image
	*/
	cv::Size _imageSize = cv::Size(480, 360);

	/*
	*
	*/
	int _heightDiv;
	int _widthDiv;

	/*
	*Boundary heights for jumping and crouching,
	*/
	int _jumpBound;
	int _crouchBound;

	/*
	*Boundary widths for moving left and right,
	*/
	int _leftBound;
	int _rightBound;

	/*
	*
	*/
	int _laneCount;

private:
	/*
	* vision thread handles all vision processing
	* terminate thread for terminating the thread and closing opencv windows if openend
	*/
	std::thread _visionThread;
	bool _terminateThread = false;

	/*
	* opencv data
	* 
	*/
	cv::Mat _src_gray;
	const int _thresh = 50;
	const int max_thresh = 255;
	const float _radius = 10;
};

