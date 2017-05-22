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
	VisionComponent();
	~VisionComponent();
	//void Update(float deltaTime) override;
	
	void CameraUpdate();
	void CalculatePosition();
};

