#include "Collision.h"
#include "CollisionComponent.h"

// Wheter objects can collide with multiple objects or not
bool multiCollide = true;

void Collision::SetMultiCollide(bool value)
{
	multiCollide = value;
}

void Collision::CheckCollision(std::vector<GameObject*> gameObjects)
{
	for(GameObject * gameObject : gameObjects)
	{
		// Check if gameObject has a CollisionComponent
		// if it doesn't continue to the next GameObject
		CollisionComponent * collider = dynamic_cast<CollisionComponent*>(gameObject->GetComponent(COLLISION_COMPONENT));
		if (collider == nullptr) continue;

		// Clear the list so old data won't be reused
		collider->_collided.clear();

		// Check every other object
		for(GameObject * collidingObject : gameObjects)
		{
			// Make sure an object can't collide with itsef
			if (gameObject == collidingObject) continue;

			// Check if the objects are colliding
			if (collider->CollidesWith(collidingObject))
			{
				// Add colliding object to the collided list
				collider->_collided.push_back(collidingObject);

				if (!multiCollide) break;
			}
		}
	}
}
