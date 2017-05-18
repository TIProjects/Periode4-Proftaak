#pragma once
#include "Vec.h"
#include <iostream>

/*
	Class : GUIElement
	A GUIElement is a part of the GUIComponent
	everything shown on the screen of UI is a GUIElement.
	This serves as a base for all the different GUIElements.
*/
class GUIElement
{
public:
	GUIElement(const GUIElement &obj) {
		_position = obj._position;
		_enabled = obj._enabled;
		_visible = obj._visible;
	};
	//Default constructor
	GUIElement() { _enabled = true; _visible = true; };
	//Constructor of GUIElement
	GUIElement(Vec3f position) { _position = position; _enabled = true; _visible = true; };
	//Sets _visible to true making the GUIElement visible.
	void Show() { _visible = true; };
	//Sets _visible to false making the GUIElement invisible.
	void Hide(){ _visible = false; };
	//Sets _enabled to true enabling the GUIElement.
	void Enable() {	_enabled = true; };
	//Sets _enabled to false disabling the GUIElement.
	void Disable() { _enabled = false; };
	//Sets the position of the GUIElement.
	void SetPosition(Vec3f position) { _position = position; };
	//Gets the position of the GUIElement.
	Vec3f GetPosition() { return _position; };
	//Draws the GUIElement if visible
	virtual void Draw() {};
	//Update function for handling events by user
	virtual void Update() {};

protected:
	//float vector for positioning GUIElement
	Vec3f _position;
	//bool _enabled for allowing change, bool _visible for allowing visibility.
	bool _enabled, _visible = true;
};