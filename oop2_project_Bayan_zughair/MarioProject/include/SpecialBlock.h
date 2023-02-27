#pragma once
#include "World_Block.h"
#include "Utilities.h"

class SpecialBlock:public WorldBlock
{
public:
	SpecialBlock(sf::Vector2f& location,block_type_t bt,int worldNum):WorldBlock(location, bt, worldNum) {}
	~SpecialBlock() = default;
};
