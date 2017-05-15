#pragma once
#include "Mesh.h"


/**
 * \brief Function for loading material into drawComponent
 * \param fileName  of the materialfile
 * \param dirName the directory of the materialFile
 * \param mesh is the component to add the _texture and material data
 */
void LoadMaterialFile(const std::string &fileName, const std::string &dirName, Mesh* mesh);

/**
 * \brief Function for creating DrawComponent
 * \param fileName the location of the .obj file which will be loaded!
 * \return DrawComponent with loaded .obj data
 */
Mesh* LoadMeshFile(const std::string& fileName);