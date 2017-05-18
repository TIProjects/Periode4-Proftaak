#pragma once
#include "Component.h"
#include <vector>
#include "GUIElement.h"
#include "DrawComponent.h"

class GUIComponent: public DrawComponent
{
public:
	//default constructor
	GUIComponent();
	//default deconstructor
	~GUIComponent() {};
	//updates any logic needed to be done by the gui
	void LateUpdate(float deltaTime) override;
	//Draws all the elements in the gui
	void Draw() override;
	//Adds an element to the gui, so it can be drawn/updated
	void AddElement(GUIElement * element);
	//list of all the elements
	std::vector<GUIElement *> _elements;

private:

};
