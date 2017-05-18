#include "Model.h"
#include <GL\freeglut.h>
#include "DrawComponent.h"
#include "CameraComponent.h"
#include <iostream>
#include "MeshDrawComponent.h"
#include "MeshFactory.h"
#include "LaneGeneratorComponent.h"
#include "CollisionComponent.h"
#include "Collision.h"
#include "GUIComponent.h"

//for testing purposes only, comment/delete when finished
#include "Text.h"
Text fpstext;
#include "LifeBar.h"
LifeBar Lifebar;

Model::Model()
{
	_lastTime = 0;
}

void Model::update()
{
	// Calculate the deltaTime
	float currentTime = glutGet(GLUT_ELAPSED_TIME) / 1000.0f;
	float deltaTime = currentTime - _lastTime;
	_lastTime = currentTime;

	// deltaTime should never be allowed to be 0 or negative...
	if (deltaTime <= 0) deltaTime = 0.000001f;

	// Calculate and display fps
	// For performance profiling only
	// should normally be commented
	fpstext.Update("fps " + to_string((int)(1.0/deltaTime)));	
//	std::cout << "Fps: " << fps << "DT: " << deltaTime << std::endl;

	// Call the Update of every GameObject
	for (GameObject * gameObject : _gameObjects)
	{
		gameObject->Update(deltaTime);
	}

	Collision::CheckCollision(_gameObjects);

	// Call the LateUpdate of every Gameobject afterwards
	for(GameObject * gameObject : _gameObjects)
	{
		gameObject->LateUpdate(deltaTime);
	}

	glutPostRedisplay();
}

void Model::InitTestObjects()
{
	// Test GameObjects
	// TODO: remove
	_lastTime = 0;

	GameObject * camera = new GameObject();
	CameraComponent * cameraComponent = new CameraComponent(1280.0f, 720.0f, 0.1f, 300.0f, 90.0f);
	camera->AddComponent(cameraComponent);

	_gameObjects.push_back(camera);

	GameObject * laneGenerator = new GameObject();
	std::vector<Mesh*> meshes;
	meshes.push_back(LoadMeshFile("Assets//Models//Lane//lanePart.Cobj"));

	LaneGeneratorComponent * laneDrawComponent = new LaneGeneratorComponent(3,10, meshes);
	laneGenerator->AddComponent(laneDrawComponent);
	laneDrawComponent->PlaceObstacleFullyRandom(LoadMeshFile("Assets//Models//TestCube//Cube.Cobj"));
	_gameObjects.push_back(laneGenerator);


	
	GameObject * guiOb = new GameObject();
	GUIComponent * GUI = new GUIComponent();

	//for testing purposes only, comment/delete when finished
	//example of GUI text
	Vec3f pos = Vec3f(10, 10, 02);
	Vec3f col = Vec3f(1, 0, 0);
	fpstext = Text(pos, col);
	GUI->AddElement(&fpstext);
	//example of lifebar
	Vec3f pos2 = Vec3f(10, 10, 0);
	std::vector<std::string> paths{ "Assets/LifeFrameBackground.psd", "Assets/LifeBar.psd", "Assets/LifeFrameSegment.psd", "Assets/LifeFrame.psd"};
	Lifebar = LifeBar(pos2, 600.0f, 50.0f, paths, 4, 3);
	GUI->AddElement(&Lifebar);
	Lifebar.Decrement();


	guiOb->AddComponent(GUI);

	_gameObjects.push_back(guiOb);

}

void Model::Init()
{
	// TODO initialise gamelogic 
}
