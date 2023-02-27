#pragma once
#include "Utilities.h"
#include "Resources.h"
#include "StaticObjects.h"
 
class WorldBlock:public StaticObjects <block_type_t>
{
public:
	WorldBlock(sf::Vector2f& location,block_type_t bt,int worldNum):StaticObjects(location,bt,worldNum) {}
	~WorldBlock() = default;
	virtual void move(float deltaTime) override {}
	virtual void animation(float deltaTime) override {}
};