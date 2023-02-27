#pragma once
#include "GameObject.h"
#include "Animation.h"
#include "StaticBlock.h"
#include "SpecialBlock.h"
//-----------------------------------------
//This is DynamicObjects class it is the
// main class of all the dynamic objects 
//----------------------------------------
class WorldBlock; 
class DynamicObjects:public GameObject
{ 
public:
	DynamicObjects(sf::Vector2f location, float speed, sf::Texture *texture);
	~DynamicObjects() = default;
	virtual void move(float deltaTime)  override;
	virtual bool isDead() {return m_dead;}
	direction getDirection() {return m_direction;}
	void switchDirection();
	sf::FloatRect getRect() const override { return m_nextSprite.getGlobalBounds(); }
	virtual void animation(float deltaTime) override;
	void setAnimation(Animation& animation) { m_animation = animation; }
	void setAnimationType(animationType animate) { m_animationType = animate; }
	virtual bool checkCollision(const sf::FloatRect& floatRect) const override;
	virtual void handleCollision(StaticBlock& block);
	virtual void handleCollision(SpecialBlock& block) {}
	void resetReagainClock() { resetClock.restart();}
	bool isResetTime()  {return (resetClock.getElapsedTime().asSeconds() > 1.0f);}
	virtual void draw(sf::RenderWindow& window) override
	{ 
	  window.draw(m_sprite); 
	  setLocation(m_sprite.getPosition());
	}
protected:
	int m_lives;
	float m_speed;
	bool m_dead = false;
	bool handleTurtle = false;
	bool isJump = false;
	sf::Sprite m_sprite;
	Animation m_animation;
	direction m_direction = direction::Right;
	animationType m_animationType = animationType::standing;
	sf::Vector2f rapidty;
	sf::Sprite m_nextSprite;
private:
	sf::Texture *m_texture;
	sf::Clock resetClock;
 };

