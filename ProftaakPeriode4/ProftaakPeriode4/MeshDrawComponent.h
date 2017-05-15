#pragma once
#include "DrawComponent.h"
#include "Mesh.h"


/** Class for drawing Meshes [See IndexedMesh.h for MeshInformation]
 * \brief IndexedMesh Drawing
 * Extends the DrawComponent class with its Draw() Function that is called by View (when drawn)
 */
class MeshDrawComponent :
	public DrawComponent
{
public:
	/**
	 *Create a MeshDrawComponent
	 * \brief Constructor for drawing IndexedMesh Objects
	 * \param mesh IndexedMesh object that will be drawn
	 */
	explicit MeshDrawComponent(Mesh * mesh);
	/**
	 * \brief 
	 */
	~MeshDrawComponent();

	/** Function from Component that is called when view wants some things drawn.
	 * \brief override draw function for drawing
	 */
	void Draw() override;

private:
	/**
	 * \brief IndexedMesh object that is drawn
	 */
	Mesh * _mesh;
};

