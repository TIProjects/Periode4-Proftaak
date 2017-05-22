#include "Sound.h"

Sound::Sound(std::string dir, bool loop)
{
	_Dir = dir;
	//check if sound neede to loop
	if (loop) _Loop = BASS_SAMPLE_LOOP;
	//Loads the soundfile
	_Stream = BASS_StreamCreateFile(FALSE, dir.c_str(), 0, 0, _Loop);
}

void Sound::Stop()
{
	if (_Stream != NULL) {
		BASS_ChannelStop(_Stream);
		BASS_StreamFree(_Stream);
		_Stream = NULL;
	}
}

void Sound::Play()
{
	if(_Stream != NULL)
		BASS_ChannelPlay(_Stream, FALSE);
}

void Sound::Pause()
{
	if (_Stream != NULL)
		BASS_ChannelPause(_Stream);
}

void Sound::Restart()
{
	_Stream = BASS_StreamCreateFile(FALSE, _Dir.c_str(), 0, 0, _Loop);
	Play();
}
