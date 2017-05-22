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
#include "bass.h"
#include "Sound.h"

//for testing purposes only, comment/delete when finished
#include "Text.h"
#include "LifeBar.h"
Text fpstext;
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
    //	int fps = int(1.0 / deltaTime);
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

	GameObject * camera = new GameObject(&_gameObjects);
	CameraComponent * cameraComponent = new CameraComponent(1280.0f, 720.0f, 0.1f, 300.0f, 90.0f);
	camera->_position = { 3.65f, 3.3f, 0.0f };
	camera->_rotation.x = 30.0f;
	camera->AddComponent(cameraComponent);

	_gameObjects.push_back(camera);

<<<<<<< HEAD
	GameObject * laneGenerator = new GameObject(&_gameObjects);
=======
	GameObject * skybox = new GameObject();
	DrawComponent * skyboxDrawComponent = new MeshDrawComponent(LoadMeshFile("Assets//Models//Skybox//skybox.Cobj"));
	skybox->_scale = { 7.0f, 7.0f, 7.0f };
	skybox->_lighting = false;
	skybox->AddComponent(skyboxDrawComponent);
	_gameObjects.push_back(skybox);

	GameObject * laneGenerator = new GameObject();
>>>>>>> 4e241ece7ac0a0db5dcc4804d55a5de1bc8c4f1a
	std::vector<Mesh*> meshes;
	meshes.push_back(LoadMeshFile("Assets//Models//Lane//lanePart.Cobj"));

	LaneGeneratorComponent * laneDrawComponent = new LaneGeneratorComponent(3,10, meshes);
	laneGenerator->AddComponent(laneDrawComponent);
	laneDrawComponent->PlaceObstacleFullyRandom(LoadMeshFile("Assets//Models//Transporter//transporter.Cobj"));
	_gameObjects.push_back(laneGenerator);

}

void Model::InitSound()
{
	//Initialize audio
	int device = -1; // Default Sounddevice (default playback device from windows settings)
	int freq = 44100; // Sample rate (Hz)
	BASS_Init(device, freq, 0, 0, NULL);

	//example on how to start sound(s)
	Sound * backgroundMusic = new Sound("Assets/background.wav", true);
	backgroundMusic->Play();

	//place this where the program closes
	//BASS_Free();
}

void Model::InitGUIElements()
{
	// create GameObject for all elements
	GameObject * guiOb = new GameObject(&_gameObjects);
	GUIComponent * GUI = new GUIComponent();


	Text * distanceCounter = new Text(Vec3f(30, 25, 0), Vec3f(0, 0, 0), "Distance: 0000 m");
	GUI->AddElement(distanceCounter);

	Text * speedCounter = new Text(Vec3f(30, 40, 0), Vec3f(0, 0, 0), "Speed: 0000 m/s");
	GUI->AddElement(speedCounter);

	Image * powerUpImage = new Image(Vec3f(1280.0f / 4.0 + 60.0f, 45, 0), 20.0f, 20.0f, "Assets/LifeBar.psd"); // Todo replace LifeBar Image
	powerUpImage->Hide();
	GUI->AddElement(powerUpImage);

	Text * powerTimeLeft = new Text(Vec3f(1280.0f / 4.0 + 100.0f, 60, 0), Vec3f(0, 0, 0), "00:00");
	powerTimeLeft->Hide();
	GUI->AddElement(powerTimeLeft);

	Text * scoreText = new Text(Vec3f(670.0f, 40, 0), Vec3f(0, 0, 0), "Score: 0000 0x");
	GUI->AddElement(scoreText);

    Text * highscore = new Text(Vec3f(670.0f, 25, 0), Vec3f(0, 0, 0), "HighScore: 0000");
    GUI->AddElement(highscore);

	Image * diededImage = new Image(Vec3f(0.0f, 0.0f, 0), 1280.0f, 720.0f, "Assets/LifeBar.psd"); // todo replace LifeBar Image
	diededImage->Hide();
	GUI->AddElement(diededImage);

	LifeBar * lifebar = new LifeBar(
		Vec3f(1280.0f / 4.0 - 100.0f, 20, 0),
		400.0f, 20.0f, 3,
		"Assets/LifeFrameBackground.psd",
		"Assets/LifeFrame.psd",
		"Assets/LifeBar.psd",
		"Assets/LifeFrameSegment.psd");

	GUI->AddElement(lifebar);

	guiOb->AddComponent(GUI);

	_gameObjects.push_back(guiOb);

    GameObject * scoreObject = new GameObject(&_gameObjects);

    scoreBoard.loadScore();
    ScoreComponent * score;

    if(!scoreBoard._scores.empty())
        score = new ScoreComponent(scoreText, highscore, scoreBoard._scores[0]->returnScore());
    else
        score = new ScoreComponent(scoreText, highscore, 0);

    scoreObject->AddComponent(score);
    scoreBoard.addScore(score);

    _gameObjects.push_back(scoreObject);

}

void Model::Init()
{
	// TODO initialise gamelogic 
	InitGUIElements();
	InitSound();
}
