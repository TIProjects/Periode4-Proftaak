#pragma once
#include "DrawComponent.h"
#include "Mesh.h"


/** Class for drawing Meshes [See Mesh.h for MeshInformation]
 * \brief Mesh Drawing
 * Extends the DrawComponent class with its Draw() Function that is called by View (when drawn)
 */
class MeshDrawComponent :
	public DrawComponent
{
public:
	/**
	 *Create a MeshDrawComponent
	 * \brief Constructor for drawing Mesh Objects
	 * \param mesh Mesh object that will be drawn
	 */
	MeshDrawComponent(Mesh * mesh);
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
	 * \brief Mesh object that is drawn
	 */
	Mesh * _mesh;
};

