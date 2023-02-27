#pragma once
#include "Utilities.h"
#include "DynamicObjects.h"
//-----------------------------------------------------------------
//This is an enemy class which control the enemys here is the 
// defintion for the movement of each the enemies & all information
//  about each enemy
//---------------------------------------------------------------
class DynamicObjects;
class Enemy:public DynamicObjects
{
 public:
	Enemy(sf::Vector2f location,float speed,sf::Texture* texture) ;
	~Enemy() = default;
	virtual void update(float deltaTime) override;
	void checkMarioLocation(const sf::Vector2f& MarioLocation);
	virtual void animation(float deltaTime) override;
	void moveToMario();
	sf::Vector2f &getMarioLocation() { return m_marioLocation; }
	bool isNearMario() { return nearMario; }
	void setSound(const sf::Sound& sound) { mario_is_around = sound; }
	void playMarioIsAround() { mario_is_around.play(); }
 private:
	bool m_dead = false;
	bool m_attacking = false;
	bool nearMario = false;
	sf::Sound mario_is_around;
	sf::Vector2f m_marioLocation;
	float m_standingTime = 5.0f;
	float m_movingTime = 3.0f;
	bool isStanding = false;
	sf::Clock movingClock;
	sf::Clock standClock;
	sf::Clock soundTime;
};