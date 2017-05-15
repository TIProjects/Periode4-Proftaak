#pragma once
#include "Vec.h"
#include <vector>
#include <list>
#include "Texture.h"
#include "Vertex.h"

using namespace std;

/**
 * \brief Class for drawing parts of .obj file
 * \_position the position of the vertex in the 3D Object
 * \_normal the normal of the vertex
 * \_textcoord the Texture coordinates on the vertex
 */
class IndexedVertex
{
public:
	int _position;
	int _normal;
	int _texcoord;
};


/** 
 * \brief The face of a .obj File loaded by MeshFactory
 * \_vertices contains a list of different Vertex (see Vertex)
 */
class Face
{
public:
	std::list<IndexedVertex> _vertices;
};


/**
 * \brief Class for saving Texture and other data as Material
 * \_name name of the material
 * \_texture the texture in the material (See Texture.h)
 */
class MaterialInfo
{
public:
	/**
	 * \brief Constructor for creating material info
	 * Cannot be initialized with name and texture because not known when created (see MeshFactory.h)
	 */
	MaterialInfo();
	;
	string _name;
	Texture * _texture;
};


/**
 * \brief Class that represents a Collection of objects 
 * \_name name of the objectgroup
 * \_materialIndex the material used in all the objects (index of _materials in IndexedMesh)
 * \_faces The different faces in the object group (See Face)
 */
class IndexedObjGroup
{
public:
	std::string _name;
	int _materialIndex;
	list<Face> _faces;
};

/**
 * \brief Class that represents a 3D Object loaded by MeshFactory
 * Contains different groups that have their own materials, faces that contain vertices and textures.
 * Can be drawn on a given position with a given rotation (Used in MeshDrawComponent.h for example)
 */
class IndexedMesh
{
public:
	/**
	 * \brief Constructor for creating empty mesh
	 */
	IndexedMesh();
	/**
	 * \brief Destructor for IndexedMesh
	 */
	~IndexedMesh();
	
	float _width;
	float _length;
	float _height;

	vector<Vec3f>	_vertices;
	vector<Vec3f>	_normals;
	vector<Vec2f>	_texcoords;
	vector<IndexedObjGroup*> _groups;
	vector<MaterialInfo*> _materials;
	/**
	 * \brief Function for drawing IndexedMesh
	 * \param position The position to be drawn on
	 * \param rotation The rotation that it should be drawn on
	 * \param rotationAngle the rotation angle that it should be drawn on
	 */
	void Draw(Vec3f position, Vec3f rotation, float rotationAngle);

};


/**
 * \brief Non-indexed Mesh class
 */
class Mesh
{
public:
	/**
	 * \brief Non-indexed obj group
	 */
	class Group
	{
	public:
		/**
		 * \brief Constructor
		 * \param material pointer to the material which will be used to draw
		 */
		explicit Group(MaterialInfo * material);

		vector<Vertex> _vertices; 
		MaterialInfo * _material; 
	};

	/**
	* \brief Constructor for creating empty mesh
	*/
	Mesh();

	/**
	 * \brief Convert an existing indexed mesh to a 
	 * buffered mesh
	 */
	explicit Mesh(const IndexedMesh * indexedMesh);

	/**
	* \brief Destructor for IndexedMesh
	* // NOTE: is empty
	*/
	~Mesh(){};

	float _width;
	float _length;
	float _height;

	vector<Group> _groups;

	/**
	* \brief Function for drawing IndexedMesh
	* \param position The position to be drawn on
	* \param rotation The rotation that it should be drawn on
	* \param rotationAngle the rotation angle that it should be drawn on
	*/
	void Draw(Vec3f position, Vec3f rotation, float rotationAngle);
};
	
