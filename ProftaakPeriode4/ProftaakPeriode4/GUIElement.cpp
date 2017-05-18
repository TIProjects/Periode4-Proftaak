#include "GUIElement.h"

GUIElement::GUIElement(Vec3f position, bool enabled, bool visible)
{
	_position = position;
	_enabled = enabled;
	_visible = visible;
}

void GUIElement::Show() {
	_visible = true;
}

void GUIElement::Hide() {
	_visible = false;
}

void GUIElement::Enable() {
	_enabled = true;
}

void GUIElement::Disable() {
	_enabled = false;
}
