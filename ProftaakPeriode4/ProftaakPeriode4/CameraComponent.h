#pragma once
#include "Component.h"

class CameraComponent : public Component
{
public:
	CameraComponent(float width, float height, float nearPlane, float farPlane, float fov);
	~CameraComponent();

	void LateUpdate(int deltaTime) override;
	void Update(int deltaTime) override;
	void ApplyCamera() const;

	float _screenWidth;
	float _screenHeight;

	float _nearPlane;
	float _farPlane;

	float _fov;
private:
	
};
