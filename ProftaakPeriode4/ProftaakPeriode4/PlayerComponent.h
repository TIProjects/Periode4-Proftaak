#pragma once
#include "Component.h"

class PlayerComponent : public Component
{
public:
	explicit PlayerComponent(int laneIndex, int laneCount, bool useOpenCV = true);

	void Update(float deltaTime) override;

	bool _isCrouching;

	bool _useOpenCV;

	int _laneCount;
	int _laneIndex;
	int _lastLane;

	bool _keyReleased;
private:
	void OpenCVUpdate(float deltaTime);
	void KeyBoardUpdate(float deltaTime);
};
