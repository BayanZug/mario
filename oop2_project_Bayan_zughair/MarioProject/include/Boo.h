#pragma once
#include "DynamicObjects.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include "Resources.h"
#include "Mario.h"
#include "Enemy.h"
//-----------------------------------------------------------------
//This is Boo class is one of the mario enemies				
// it can attacking and fly so it  can hurt mario but mario can
// attacking it by press A keys
//-----------------------------------------------------------------
class Mario;
class WorldBlock;
class Boo:public Enemy
{
public:
	~Boo() = default;
	void handleCollision(Mario& mario);
	virtual void update(float deltaTime) override;
	Boo(sf::Vector2f location, bool& soundOn, int& difficulty);
	virtual void handleCollision(StaticBlock& block) override
	{
		DynamicObjects::handleCollision(block);
	}
	virtual void handleCollision(SpecialBlock& block) override
	{
		DynamicObjects::handleCollision(block);
	}
};