#include "GUIComponent.h"
#include <GL/freeglut.h>

GUIComponent::GUIComponent()
{

}

void GUIComponent::LateUpdate(float DeltaTime)
{
	//UPDATE GUI, CHECK FOR INPUT
	for (GUIElement * element : _elements)
	{
		element->Update();
	}
}

void GUIComponent::Draw() {
	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);

	for (GUIElement * element : _elements)
	{
		element->Draw();
	}
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
}

void GUIComponent::AddElement(GUIElement * element) {
	_elements.push_back(element);
}
