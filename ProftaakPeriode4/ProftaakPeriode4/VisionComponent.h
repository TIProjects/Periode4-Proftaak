#pragma once
#include "Component.h"
#include <opencv2\opencv.hpp>
#include <iostream>
#include <string>
#include <thread>



class VisionComponent : public Component
{
public:
	VisionComponent();
	~VisionComponent();
	
	void CameraUpdate();
};

