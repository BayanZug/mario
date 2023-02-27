#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Resources.h"
#include "Mario.h"
#include "Enemy.h"
#include "Animation.h"

//---------------------------------------------------
//This is a Spiny class is one of mario enemies.
//the spiny is spiky so mario shouldn't touch
//  it because it hurt him he cant attack it.
//---------------------------------------------------
class Mario;
class Enemy;
class Spiny : public Enemy
{
public:
	Spiny(sf::Vector2f location);
	~Spiny() = default;
	virtual void update(float deltaTime) override
	{
		if (jumpClock.getElapsedTime().asSeconds() > jumpTime)
		{
			rapidty.y = -sqrtf(2.0f * 1200.0f * JUMP_DISTANCE); 
			jumpClock.restart();
		}
		Enemy::update(deltaTime);
	}
	void handleCollision(Mario& mario);
	virtual void handleCollision(StaticBlock& block) override
	{
		DynamicObjects::handleCollision(block);
	}
	virtual void handleCollision(SpecialBlock& block) override
	{
		DynamicObjects::handleCollision(block);
	}
private:
	float jumpTime = 1;
	bool isJump = true;
	sf::Clock jumpClock;
};

