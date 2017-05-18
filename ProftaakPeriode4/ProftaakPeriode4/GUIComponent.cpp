#include "GUIComponent.h"

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

	for (GUIElement * element : _elements)
	{
		element->Draw();
	}
}

void GUIComponent::AddElement(GUIElement * element) {
	_elements.push_back(element);
}
