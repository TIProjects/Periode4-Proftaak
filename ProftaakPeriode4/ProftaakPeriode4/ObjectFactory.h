#pragma once
#include <list>
// #include "Component.h"
#include "TextureLoader.h"
#include "DrawComponent.h"

// Forward decleration needed because DrawComponent needs this header
// While this header also needs the DrawComponent header.
// Since they both need eachother they should include one another, but 
// this is impossible...
class DrawComponent;
class GameObject;

/*
 * Class needed for creating a gameobject
 * Vertex is a triangle for drawing which can contain a texture (MaterialInfo)
 * 
 */
class Vertex
	{
	public:
		int position;
		int normal;
		int texcoord; 
	};
/*
 * Face contains a list of different vertices that are combined
 */
class Face
	{
	public:
		std::list<Vertex> vertices;
	};
/*
 * MaterialInfo is a class for saving texture and possible other future data
 * @stefan --> yes i do not init with name and texture, i do this because the name and texture
 * are read from a file so i don't know in which order they are found.
 */
class MaterialInfo
	{
	public:
		MaterialInfo()
	{
	}
	;
		std::string name;
		Texture * texture;
	};
/*
 * class for combining different objects which are used together
 */
class ObjGroup
	{
	public:
		std::string name;
		int materialIndex;
		std::list<Face> faces;
	};

/*
 * Function for loading material into drawComponent
 * \fileName of the materialfile
 * \dirName the directory of the materialFile
 * \drawComponent is the component to add the texture and material data
 */
void loadMaterialFile(const std::string &fileName, const std::string &dirName, DrawComponent * component);
/*
 * Function for creating DrawComponent
 * \fileName the location of the .obj file which will be loaded!
 * returns DrawComponent with loaded .obj data
 */
DrawComponent * LoadComponent(const std::string &fileName, GameObject * gameObject);