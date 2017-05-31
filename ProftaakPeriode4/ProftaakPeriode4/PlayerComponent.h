#pragma once
#include "Component.h"
#include "Vec.h"
#include "LifeBar.h"
#include "Model.h"

class PlayerComponent : public Component
{
public:
	/**
	* \brief Constructor for PlayerComponent
	* \param laneIndex the current lane the player is on
	* \param laneCount the amount of lanes
	* \param useOpenCV Wether the
	*/
	explicit PlayerComponent(int laneIndex, int laneCount, LifeBar * lifeBar, Image * gameOverScreen, Model * model, bool useOpenCV = true);
	/**
	* \brief Overriden update from Component
	* \param deltaTime Update the playercomponent by changing position and checking user input
	*/
	void Update(float deltaTime) override;
	/**
	* \brief Set the x coordinate of the targetPosition to which the player will move
	* \param xCoord
	*/
	void MovePlayer(float xCoord);

	/**
	 * \brief Wether the player is crouching or not
	 */
	bool _isCrouching;
	/**
	 * \brief Wether OpenCV is used for input or not
	 */
	bool _useOpenCV;
	/**
	 * \brief The amount of lanes present
	 */
	int _laneCount;
	/**
	 * \brief The current lane the player is on
	 */
	int _laneIndex;
	/**
	 * \brief The last lane the player was on
	 */
	int _lastLane;
    /**
    * \brief time of the invincibility powerup
    */
    bool _isInvinsible;
	/**
	 * \brief Time of invincibility after a collision
	 */
	bool _collided;
	/**
	 * \brief Wether the last keyboard key was released
	 */
	bool _keyReleased;

	/**
	 * \brief Model used to reset the game
	 */
	Model * _model;
	/**
	 * \brief The gameOverscreen which will be shwon
	 */
	Image * _gameOverScreen;
	/**
	 * \brief The position to which the player will be moved
	 * NOTE: only the x coord is acounted for
	 */
	Vec3f _targetPosition;
	/**
	 * \brief the lifeBar which will be updated
	 */
	LifeBar * _lifeBar;
private:
	/**
	 * \brief Update the player based on openCV input
	 * \param deltaTime the deltaTime
	 */
	void OpenCVUpdate(float deltaTime);
	/**
	 * \brief Update the player base on Keyboard input
	 * \param deltaTime the deltaTime
	 */
	void KeyBoardUpdate(float deltaTime);

	/**
	 * \brief Keeping track of time to make sure the player can only be hit once
	 */
	float _hitTime;
};
