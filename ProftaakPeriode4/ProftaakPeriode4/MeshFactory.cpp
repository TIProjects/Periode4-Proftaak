#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include "Texture.h"
#include <string>
#include "Vec.h"
#include "MeshFactory.h"
#include "Mesh.h"

/**
* Replaces a substring in a string
*/
static std::string replace(std::string str, const std::string &toReplace, const std::string &replacement)
{
	size_t index = 0;
	while (true) 
	{
		 index = str.find(toReplace, index);
		 if (index == std::string::npos) 
			 break;
		 str.replace(index, toReplace.length(), replacement);
		 ++index;
	}
	return str;
}

/**
* Splits a string into substrings, based on a seperator
*/
static std::vector<std::string> split(std::string str, const std::string &seperator)
{
	std::vector<std::string> ret;
	size_t index;
	while(true)
	{
		index = str.find(seperator);
		if(index == std::string::npos)
			break;
		ret.push_back(str.substr(0, index));
		str = str.substr(index+1);
	}
	ret.push_back(str);
	return ret;
}

/**
* Turns a string to lowercase
*/
static inline std::string toLower(std::string data)
{
	std::transform(data.begin(), data.end(), data.begin(), ::tolower);
	return data;
}


/**
* Cleans up a line for processing
*/
static inline std::string cleanLine(std::string line)
{
	line = replace(line, "\t", " ");
	while (line.find("  ") != std::string::npos)
		line = replace(line, "  ", " ");
	if (line == "")
		return "";
	if (line[0] == ' ')
		line = line.substr(1);
	if (line == "")
		return "";
	if (line[line.length() - 1] == ' ')
		line = line.substr(0, line.length() - 1);
	return line;
}






void LoadMaterialFile(const std::string &fileName, const std::string &dirName, IndexedMesh* mesh)
{
	std::cout << "Loading " << fileName << std::endl;
	std::ifstream pFile(fileName.c_str());
	if (!pFile.is_open())
	{
		std::cout << "Could not open file " << fileName << std::endl;
		return;
	}

	MaterialInfo* currentMaterial = NULL;

	while(!pFile.eof())
	{
		std::string line;
		std::getline(pFile, line);
		line = cleanLine(line);
		if(line == "" || line[0] == '#')
			continue;

		std::vector<std::string> params = split(line, " ");
		params[0] = toLower(params[0]);

		if(params[0] == "newmtl")
		{
			if(currentMaterial != NULL)
			{
				mesh->_materials.push_back(currentMaterial);
			}
			currentMaterial = new MaterialInfo();
			currentMaterial->_name = params[1];
		}
		else if(params[0] == "map_kd")
		{
			std::string tex = params[1];
			if (tex.find("/"))
				tex = tex.substr(tex.rfind("/") + 1);
			if (tex.find("\\"))
				tex = tex.substr(tex.rfind("\\") + 1);
			std::string texture = dirName + "/" + tex;
			currentMaterial->_texture = LoadTexture(texture.c_str());
			std::cout << dirName << "/" << tex << std::endl;



		} 
		else if (params[0] == "kd")
		{//TODO, diffuse color
		}
		else if (params[0] == "ka")
		{//TODO, ambient color
		}
		else if (params[0] == "ks")
		{//TODO, specular color
		}
		else if (
			params[0] == "illum" || 
			params[0] == "map_bump" || 
			params[0] == "map_ke" || 
			params[0] == "map_ka" ||
			params[0] == "map_d" ||
			params[0] == "d" ||
			params[0] == "ke" ||
			params[0] == "ns" ||
			params[0] == "ni" ||
			params[0] == "td" ||
			params[0] == "tf" ||
			params[0] == "tr" ||
			false)
		{
			//these values are usually not used for rendering at this time, so ignore them
		}
		else
			std::cout<<"Didn't parse "<<params[0]<<" in material file"<<std::endl;
	}
	if(currentMaterial != NULL){
		mesh->_materials.push_back(currentMaterial);
	}

}

Mesh* LoadMeshFile(const std::string& fileName)
	{
		IndexedMesh* indexedMesh = new IndexedMesh();
		std::cout << "Loading " << fileName << std::endl;
		std::string dirName = fileName;
		if (dirName.rfind("/") != std::string::npos)
			dirName = dirName.substr(0, dirName.rfind("/"));
		if (dirName.rfind("\\") != std::string::npos)
			dirName = dirName.substr(0, dirName.rfind("\\"));
		if (fileName == dirName)
			dirName = "";


		std::ifstream pFile(fileName.c_str());

		if (!pFile.is_open())
		{
			std::cout << "Could not open file " << fileName << std::endl;
			return nullptr;
		}


		IndexedObjGroup* currentGroup = new IndexedObjGroup();
		currentGroup->_materialIndex = -1;


		while (!pFile.eof())
		{
			std::string line;
			std::getline(pFile, line);
			line = cleanLine(line);
			if (line == "" || line[0] == '#') //skip empty or commented line
				continue;

			std::vector<std::string> params = split(line, " ");
			params[0] = toLower(params[0]);

			if (params[0] == "v")
				indexedMesh->_vertices.push_back(Vec3f((float)atof(params[1].c_str()), (float)atof(params[2].c_str()), (float)atof(params[3].c_str())));
			else if (params[0] == "vn")
				indexedMesh->_normals.push_back(Vec3f((float)atof(params[1].c_str()), (float)atof(params[2].c_str()), (float)atof(params[3].c_str())));
			else if (params[0] == "vt")
				indexedMesh->_texcoords.push_back(Vec2f((float)atof(params[1].c_str()), (float)atof(params[2].c_str())));
			else if (params[0] == "f")
			{
				for (size_t ii = 4; ii <= params.size(); ii++)
				{
					Face face;

					for (size_t i = ii - 3; i < ii; i++)	//magische forlus om van quads triangles te maken ;)
					{
						IndexedVertex vertex;
						std::vector<std::string> indices = split(params[i == (ii - 3) ? 1 : i], "/");
						if (indices.size() >= 1)	//er is een positie
							vertex._position = atoi(indices[0].c_str()) - 1;
						if (indices.size() == 2)		//alleen _texture
							vertex._texcoord = atoi(indices[1].c_str()) - 1;
						if (indices.size() == 3)		//v/t/n of v//n
						{
							if (indices[1] != "")
								vertex._texcoord = atoi(indices[1].c_str()) - 1;
							vertex._normal = atoi(indices[2].c_str()) - 1;
						}
						face._vertices.push_back(vertex);
					}
					currentGroup->_faces.push_back(face);
				}
			}
			else if (params[0] == "s")
			{//smoothing groups
			}
			else if (params[0] == "mtllib")
			{
				LoadMaterialFile(dirName + "/" + params[1], dirName, indexedMesh);
			}else if(params[0] == "w")
			{
				indexedMesh->_width = float(std::stoi(params[1]));
			}else if(params[0] == "l")
			{
				indexedMesh->_length = float(std::stoi(params[1]));
			}
			else if (params[0] == "h")
			{
				indexedMesh->_height = float(std::stoi(params[1]));
			}
			else if (params[0] == "usemtl")
			{
				if (currentGroup->_faces.size() != 0)
					indexedMesh->_groups.push_back(currentGroup);
				currentGroup = new IndexedObjGroup();
				currentGroup->_materialIndex = -1;

				for (int i = 0; i < indexedMesh->_materials.size(); i++)
				{
					MaterialInfo* info = indexedMesh->_materials[i];
					if (info->_name == params[1])
					{
						currentGroup->_materialIndex = i;
						break;
					}
				}
				if (currentGroup->_materialIndex == -1)
					cout << "Could not find material _name " << params[1] << endl;
			}
		}
		indexedMesh->_groups.push_back(currentGroup);
		return new Mesh(indexedMesh);;
	}




