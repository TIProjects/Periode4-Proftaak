#pragma once

#include "bass.h"
#include <string>

/*
	Class Sound
	with this class you can play an sound from anywhere in the code
	this class also haves the functions of stop play pause and restart
*/

class Sound
{
public:
	//constructor with dir as path of file and loop as a boolean wether it should loop or not
	Sound(std::string dir, bool loop);
	//default deconstructor
	~Sound() {};
	//default constructor
	Sound() {};
	//Stop function: this functions stops the sound and frees the stream THIS SOUND IS NOT USABLE AFTER THIS FUNCTION
	//Use Restart to start using this sound again
	void Stop();
	//Play function: this functions plays the sound
	void Play();
	//Pause function: this functions pauses the sound
	void Pause();
	//Restart function: this function resets the stream and plays the sound again
	void Restart();

private:
	HSTREAM _Stream;
	std::string _Dir;
	int _Loop = 0;
};