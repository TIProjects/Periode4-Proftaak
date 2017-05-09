#include <GL/freeglut.h>
// #include "Component.h"
#include "CameraComponent.h"
#include "GameObject.h"
#include "Vec.h"
#include "Input.h"

CameraComponent::CameraComponent(float  width, float height, float nearPlane, float farPlane, float fov)
: Component(CAMERA_COMPONENT)
{
	_screenWidth = width;
	_screenHeight = height;

	_nearPlane = nearPlane; 
	_farPlane = farPlane;

	_fov = fov;
}

CameraComponent::~CameraComponent()
{
}

void CameraComponent::LateUpdate(int deltaTime)
{
}

void CameraComponent::Update(int deltaTime)
{
	Vec2i mousePos(Mouse::GetMousePos());

	// Calculate mouse movement and reset mouse
	float dx = float(mousePos.x) - _screenWidth/ 2;
	float dy = float(mousePos.y) - _screenHeight/ 2;
	if ((dx != 0 || dy != 0) && abs(dx) < 400 && abs(dy) < 400)
	{
		// TODO: test
//		_parent->_rotation.y += dx / 10.0f;
//		_parent->_rotation.x += dy / 10.0f;
//		glutWarpPointer(int(_screenWidth / 2), int(_screenHeight / 2));
	}
}

void CameraComponent::ApplyCamera() const
{
	// Apply camera settings
	gluPerspective(_fov, _screenWidth / float(_screenHeight), _nearPlane, _farPlane);

	// Rotate and translate the camera
	glRotatef(_parent->_rotation.x, 1, 0, 0);
	glRotatef(_parent->_rotation.y, 0, 1, 0);
	glTranslatef(_parent->_rotation.x, _parent->_rotation.y, _parent->_rotation.z);
}
