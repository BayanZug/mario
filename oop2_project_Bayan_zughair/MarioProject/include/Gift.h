#pragma once
#include "Utilities.h"
#include "Mario.h"
#include "Resources.h"
#include "StaticObjects.h"
//--------------------------------------------
//This template Class for the Gifts objects
// thats mean here is all the defintion of
// gifts effects on the game.
//-------------------------------------------
class Mario; 
class Gift : public StaticObjects <giftType>
{
public:
	Gift(sf::Vector2f& location, giftType gt);
	~Gift() = default;
	virtual void handleCollision(Mario& m);
	virtual void move(float deltaTime) override {}
	virtual void animation(float deltaTime) override;
	sf::Sound& getGiftSound() { return m_sound; }
protected:
	sf::Sound m_sound;
private:
	int coinIndex = 0;
	int starIndex = 0,flagIndex = 0,
	mashroomIndex = 0;
	giftType m_animation;
	float switchTime = 32.5;
	std::vector<sf::IntRect> m_coinVector  = Resources::loadResources().getCoin(),
		m_flagVector = Resources::loadResources().getFlag(),
		m_starVector = Resources::loadResources().getStar(),
		m_mashroomVector = Resources::loadResources().getMashroom();
};