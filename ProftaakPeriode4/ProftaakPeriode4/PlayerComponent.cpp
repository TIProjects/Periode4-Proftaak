#include "PlayerComponent.h"
#include "Input.h"

PlayerComponent::PlayerComponent(int laneIndex, int laneCount, bool useOpenCV)
: Component(PLAYER_COMPONENT)
{
	_laneCount = laneCount;
	_isCrouching = false;
	_laneIndex = laneIndex;
	_useOpenCV = useOpenCV;
	_keyReleased = true;
	_lastLane = _laneIndex;
}

void PlayerComponent::Update(float deltaTime)
{
	if(_useOpenCV)
		OpenCVUpdate(deltaTime);
	else
		KeyBoardUpdate(deltaTime);
}

void PlayerComponent::OpenCVUpdate(float deltaTime)
{
	// TODO Update laneIndex using openCV
}

void PlayerComponent::KeyBoardUpdate(float deltaTime)
{
	const bool * keys = Keyboard::GetKeyboard();

	if (_keyReleased && keys['a'] && _laneIndex - 1 >= 0) {
		_lastLane = _laneIndex;
		_laneIndex -= 1;
		_keyReleased = false;
	}
	if (_keyReleased && keys['d'] && _laneIndex + 1 < _laneCount) {
		_lastLane = _laneIndex;
		_laneIndex += 1;
		_keyReleased = false;
	}
	if (!keys['d'] && !keys['a']) _keyReleased = true;

	_isCrouching = keys['s'];
}