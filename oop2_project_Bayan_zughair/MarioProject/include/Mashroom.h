#pragma once
#include "Gift.h"
#include "Utilities.h"
//----------------------------------
// this class for the Mashroom gift 
// when mario take it he will save 
// his place so when he lose one of his
// heart he restart the level
// from the Mashroom place not from the
// start level point 
//---------------------------------
class Mashroom:public Gift
{
public:
	Mashroom(sf::Vector2f location , giftType gt, bool soundOn):Gift(location,gt)
	{
		if (soundOn)
			m_sound.setBuffer(Resources::loadResources().getSoundBuffer(sound_t::sound_mushroom));
	}
	~Mashroom() = default;
	virtual void handleCollision(Mario& m) override {}
};