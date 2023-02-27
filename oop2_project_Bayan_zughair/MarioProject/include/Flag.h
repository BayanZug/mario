#pragma once
#include "Gift.h"
#include "Utilities.h"
//-----------------------------
// this class for the flag gift 
// which mario should take it to
// end the current level and
// passsed to the next level
//-----------------------------
class Flag:public Gift
{
public:
	Flag(sf::Vector2f location , giftType gt, bool soundOn):Gift(location,gt)
	{
		if (soundOn)
			m_sound.setBuffer(Resources::loadResources().getSoundBuffer(sound_t::sound_gift));
	}
	~Flag() = default;
	void handleCollision(Mario& m) {}// shouldn't delete
};