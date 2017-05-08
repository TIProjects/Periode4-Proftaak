#pragma once

#include "Vec.h"
#include <vector>
#include "Component.h"

class GameObject {
public:
	/*
	* Constructor for creating object
	* @param vertices as Vector with Matrix3GLf
	*/
	GameObject(std::vector<Vec3f> vertices);
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
	* Get the Component based on the parameter id
	* if it is present
	* @param ComponentID: The id which will be searched for
	* @return Component *: The pointer to the Component with the specified id,
	* or nullptr if no Component with the specified id 
	* is present in this object
	*/
	Component * GetComponent(ComponentID id);
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
	std::vector<Component> _components;
	
};
