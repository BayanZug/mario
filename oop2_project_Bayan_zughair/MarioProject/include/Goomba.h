#pragma once
#include <vector>
#include "Resources.h"
#include "Mario.h"
#include "Enemy.h"
#include "Utilities.h"


class Mario;
class Goomba:public Enemy
{
public:
	Goomba(sf::Vector2f location, bool& soundOn, int& difficulty);
	~Goomba() = default;
	void handleCollision(Mario& mario);
	virtual void handleCollision(StaticBlock& block) override
	{
		DynamicObjects::handleCollision(block);
	}
	virtual void handleCollision(SpecialBlock& block) override
	{
		DynamicObjects::handleCollision(block);
	}
};