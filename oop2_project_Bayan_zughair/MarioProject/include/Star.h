#pragma once
#include "Gift.h"
#include "Utilities.h"
// ----------------------------------
// this class for the star gift 
// which increase one life for mario 
//---------------------------------
class Star:public Gift
{
public:
  Star(sf::Vector2f location,giftType gt,bool soundOn):Gift(location, gt) 
  {
	if (soundOn)
    	m_sound.setBuffer(Resources::loadResources().getSoundBuffer(sound_t::sound_star));
  }
  ~Star() = default;
};