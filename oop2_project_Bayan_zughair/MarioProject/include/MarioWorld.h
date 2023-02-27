#pragma once
#include "Utilities.h"
#include "Mario.h"
#include "Enemy.h"
#include "GameObject.h"
#include "StaticObjects.h"
#include "Turtle.h"
#include "Goomba.h"
#include "Boo.h"
#include "ExtraAccesorios.h"
#include "World_Block.h"
#include "Collision.h"
#include "Coin.h"
#include "Star.h"
#include "Flag.h"
#include "Mashroom.h"
#include <vector>
#include <typeinfo>
#include <fstream>
#include <algorithm>

class MarioWorld
{
public:
	
	MarioWorld(bool&,bool&,int&);
	~MarioWorld() = default;
	void create_board();
	void draw(sf::RenderWindow& window);
	void collision();
	void addObject(char c, sf::Vector2f&);
	void moveCharacters(sf::Time deltaTime);
	sf::Vector2f& getmarioPosition() { return m_mario->getLocation(); }
	void addCharacter(char c, sf::Vector2f& sfLocation);
	bool checkFinish() { return m_levelFinished; }
	void finish();
	void drawBackground(sf::RenderWindow&);
	void updateView(sf::View& view);
	bool failed() { return levelFailed; }
	void addGift(giftType gt, const sf::Vector2f& sfLocation);
	bool gameOver() { return m_gameOver; }
	void setMusic(const bool& music);
	void setSoundEffects(const bool& sound);
	int getLevelIndex() { return levelIndex; }
private:
	Mario* m_mario;
	int m_difficult = 1;
	bool levelFailed = false;
	float viewSpeed = 4.0f;
	int index = 0;
	int levelIndex = 0;
	int mariolevelNumber = 1;  
	sf::Clock viewSpeedClock;
	std::vector<std::unique_ptr<GameObject> > gameObjects;
	std::vector<std::string> level_file;
	sf::Vector2f m_destination;
	sf::Vector2f m_startingPosition;	
	bool m_levelFinished = false;
	std::vector<std::string> levels;
	sf::Vector2f m_viewCenter;
	sf::Vector2f m_viewSize;
	sf::Sprite m_background;
	bool m_gameOver = false;
	bool resetView = false;
	bool musicOn;
	bool soundEffects = true;
	sf::Sound  m_music;
};
bool collide(GameObject& obj1, GameObject& obj2);
