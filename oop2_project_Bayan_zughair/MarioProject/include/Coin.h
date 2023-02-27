#pragma once
#include "Gift.h"
#include "Utilities.h"
//-----------------------------
// this class for the coin gift 
// when mario take it he will
// get blood for his heart
//-----------------------------
class Coin:public Gift
{
public:
  Coin(sf::Vector2f location,giftType gt,bool soundOn):Gift(location,gt)
  {
	if (soundOn)
	  m_sound.setBuffer(Resources::loadResources().getSoundBuffer(sound_t::sound_gift));
  }
  ~Coin() = default;
};