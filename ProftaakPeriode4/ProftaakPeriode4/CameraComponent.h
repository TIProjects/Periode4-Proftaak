#pragma once
#include "Component.h"

class CameraComponent : public Component
{
public:
	CameraComponent(int width, int height, int nearPlane, int farPlane, int fov, GameObject * parent);
	~CameraComponent();

	void LateUpdate(int deltaTime) override;
	void Update(int deltaTime) override;
	void ApplyCamera() const;

	int _screenWidth;
	int _screenHeight;

	int _nearPlane;
	int _farPlane;

	int _fov;
private:
	
};
