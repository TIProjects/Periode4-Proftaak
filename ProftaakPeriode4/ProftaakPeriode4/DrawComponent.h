#pragma once
#include "Component.h"
#include <vector>
#include "Vec.h"
#include "ObjectFactory.h"

class Component;
class GameObject;

/*
 * Class for drawing gameObjects
 * Created by ObjectFactory
 */
class DrawComponent : public Component
{
public:
	DrawComponent();
	~DrawComponent();

	// drawing (deltaTime not implemented)
	void Draw();

	std::vector<Vec3f>	vertices;
	std::vector<Vec3f>	normals;
	std::vector<Vec2f>	texcoords;
	std::vector<ObjGroup*> groups;
	std::vector<MaterialInfo*> materials;
};
