#pragma once
#include "Utilities.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include "Resources.h"
#include "DynamicObjects.h"
#include "Goomba.h"
#include "Spiny.h"
#include "Gift.h"
#include "ExtraAccesorios.h"
#include "Boo.h"
//-----------------------------------------------------------------
//This is Mario class which is the main character in the game
//-----------------------------------------------------------------
class Turtle;	
class Goomba;
class Spiny;		
class Gift;
class Boo;
class DynamicObjects;
class ExtraAccesorios;
class WorldBlock;
class Mario:public DynamicObjects 
{
public:
	Mario(sf::Vector2f location, bool &soundOn);
	~Mario() = default;
	virtual void update(float deltaTime) override;
	bool mariojump() {return m_animation.isJump();}
	void handleCollision(Gift& gift);
	void handleCollision(Turtle& tur);
	virtual void handleCollision(Goomba& goomba);
	void handleCollision(Spiny&);
    void handleCollision(Boo& boo);
	void handlewithEnemy(float enemyX);
	void handleCollision(ExtraAccesorios& extraAccesorios);
	void setHealth() {m_sprite.setPosition(getStartingLocation()); m_blood = 5;}
	bool isAttacking() {return m_animation.isAttack();}
	bool isOut() {return (m_blood == 0);}
	void showStats(sf::RenderWindow& window, sf::Vector2f viewCenter);
	bool finished() {return m_finished;}
	void checkLimits(const sf::Vector2f& viewSize);
	virtual void handleCollision(StaticBlock& block) override
	{
		DynamicObjects::handleCollision(block);
	}
	virtual void handleCollision(SpecialBlock& block) override
	{
		DynamicObjects::handleCollision(block);
	}
	void resetSpeed() {m_speed = MARIO_SPEED;}
	void speedUp() { m_speed *= speedBonus; }
private:
	sf::Sprite m_data;
	sf::Vector2f m_newLocation;
	std::vector<sf::IntRect> m_dataHeartrectVector = Resources::loadResources().getmarioDataheart();
	std::vector<sf::IntRect> m_dataHealthBarrectVector = Resources::loadResources().getmariohealth();
	std::vector<sf::IntRect> m_marioheartedVector = Resources::loadResources().getMarioGetHeartRect();
	int m_blood = 5;
	float switchTime = 32;
	bool switchDirection = false;
	bool m_finished = false;
	float speedBonus = 1.07f;
	sf::Text lifenum;
	sf::Sound jump;
	sf::Sound failure;
	sf::Sound attacking;
	sf::Sound hit;
	sf::Sound fallingSound;
	sf::Sound giftSound;
	sf::Sprite m_bloodBar;
	sf::Sound mushroomSound;
	sf::Clock m_jumpingClock;
};

