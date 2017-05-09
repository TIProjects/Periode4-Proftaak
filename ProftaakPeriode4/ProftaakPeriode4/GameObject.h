﻿#pragma once

#include "Vec.h"
#include <vector>
#include "Component.h"
#include "DrawComponent.h"

class DrawComponent;
class Component;
enum ComponentID;

class GameObject {
public:
	/*
	* Constructor for creating object
	* @param vertices as Vector with Matrix3GLf
	*/
	GameObject();
	/*
	* Update function will call the update function
	* of every Component in this GameObject
	* Update should only be called by the idleFunc
	* @param int deltaTime: the time in milliseconds between the current and last frame
	*/
	void Update(int deltaTime);
	/*
	* LateUpdate function will call the LateUpdate function
	* of every Component in this GameObject
	* 
	* LateUpdate should only be called by the idleFunc, and only after
	* calling every update
	* @param int deltaTime: the time in milliseconds between the current and last frame
	*/
	void LateUpdate(int deltaTime);
	/*
	* Set current position
	* @param position as new position
	*/
	void SetPosition(Vec3f position);
	/*
	* Rotate the object (add new values to current rotation)
	* @param rotation to add to the current rotation
	*/
	void Rotate(Vec3f rotation);
	/*
	* Set the current rotation of the object
	* @param rotation as new rotation
	*/
	void SetRotation(Vec3f rotation);
	/*
	 * Draw this GameObject using it's DrawComponent
	 * if it has one
	 */
	void Draw();
	/*
	* Get the Component based on the parameter id
	* if it is present
	* @param ComponentID: The id which will be searched for
	* @return Component *: The pointer to the Component with the specified id,
	* or nullptr if no Component with the specified id 
	* is present in this object
	*/
	Component * GetComponent(ComponentID id);
	/*
	 * Add a component to this GameObject. 
	 * @param Component: The component which will be added
	 */
	void AddComponent(Component * component);
	/*
	 * Remove a component from this GameObject
	 * @param Component *: The pointer to the component which will be removed
	 * @return bool: True if removing the component was successful, or false
	 * if the component wasn't removed, or it wasn't present in this GameObject 
	 */
	bool RemoveComponent(Component * component);
	/*
	 * The component used to draw this GameObject
	 */
	DrawComponent * _drawComponent = nullptr;
	/*
	* The current origin of the object
	*/
	Vec3f _position;
	/*
	* The current rotation of the object
	*/
	Vec3f _rotation;
private:	
	/*
	 * Vector of every Component in this GameObject
	 */
	std::vector<Component *> _components;
	
};
