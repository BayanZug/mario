#pragma once
#include "DynamicObjects.h"
#include "Mario.h"
#include "Enemy.h"
#include "Resources.h"
#include <vector>
#include <SFML/Graphics.hpp>

// ------------------------------------------ -
//This is a turtle class is one of mario enemies.
// turtle walks and can hurt mario but he can fight it
// but if mario jump on it it will die
//------------------------------------------------------
class Mario;
class Turtle:public Enemy 
{
public:
	Turtle(sf::Vector2f location);
	~Turtle() = default;
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
	float switchTime = 12;
};





