#pragma once
#include "GameObject.h"		

class Hitbox
{
public:
	/**
	* \brief Constructor for Hitbox
	* \param dimensions The dimensions of the hitbox
	* \param offset The offset of the hitbox relative to it's parent GameObject
	*/
	Hitbox(Vec3f dimensions, Vec3f offset);
	/**
	 * \brief Copy constructor for Hitbox
	 * \param other the Hitbox which will be copied
	 */
	Hitbox(const Hitbox& other);
	/**
	 * \brief Default constructor for Hitbox
	 * will initialise every vector value with 0.0f
	 */
	Hitbox();

	// The dimensions of the hitbox
	Vec3f _dimensions;
	// The offset of the hitbox relative to it's parent GameObject
	Vec3f _offset;
};

class CollisionComponent : public Component
{
public:
	/**
	 * \brief Constructor which takes only a single hitbox
	 * \param hitbox will be used to detect collision
	 */
	explicit CollisionComponent(Hitbox hitbox);
	/**
	 * \brief Constructor which takes a vector of hitboxes
	 * \param hitboxes will be used to detect collision
	 */
	explicit CollisionComponent(std::vector<Hitbox> hitboxes);

	/**
	 * \brief Check if this component can and does collide with another GameObject
	 * \param other the GameObject with which collision will be checked
	 * \return true if there is a collision and false if there is no collision, 
	 * or the other object does not have a collider
	 */
	bool CollidesWith(GameObject * other) const;

	// List of objects that collided with this component
	std::vector<GameObject *> _collided;
	// The list of hitboxes which will be used when checking collision
	std::vector<Hitbox> _hitboxes;
};
