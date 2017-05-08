#pragma once
#include "Component.h"
#include <vector>
#include "Vec.h"
#include "ObjectFactory.h"

/*
 * Class for drawing gameObjects
 * Created by ObjectFactory
 */
class DrawComponent : Component
{
public:
	DrawComponent(GameObject * parent);
	~DrawComponent();

	// drawing (deltaTime not implemented)
	void Update(int deltaTime) override;

	std::vector<Vec3f>	vertices;
	std::vector<Vec3f>	normals;
	std::vector<Vec2f>	texcoords;
	std::vector<ObjGroup*> groups;
	std::vector<MaterialInfo*> materials;
};
