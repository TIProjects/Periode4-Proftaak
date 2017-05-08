#include <GL/freeglut.h>
// #include "Component.h"
#include "CameraComponent.h"
#include "Vec.h"
#include "Input.h"

CameraComponent::CameraComponent(int width, int height, int nearPlane, int farPlane, int fov, GameObject * parent) 
: Component(CAMERA_COMPONENT, parent)
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
	int dx = mousePos.x - _screenWidth/ 2;
	int dy = mousePos.y - _screenHeight/ 2;
	if ((dx != 0 || dy != 0) && abs(dx) < 400 && abs(dy) < 400)
	{
		_parent->_rotation.y += dx / 10.0f;
		_parent->_rotation.x += dy / 10.0f;
		glutWarpPointer(_screenWidth / 2, _screenHeight / 2);
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
