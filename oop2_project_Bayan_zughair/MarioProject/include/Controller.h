#pragma once
#include "Utilities.h"
#include "MarioWorld.h"
//---------------------------------------------
//This is a Controller class which controll the
// games & run it		
//----------------------------------------------
class Controller 
{
public:
	Controller(sf::RenderWindow&,bool,bool,int);
	~Controller() = default;
	void run();
	void textNextLevel();
	void textStart();
	bool pauseGame();
	void textFailed();
private:
	sf::View m_view;
	sf::RenderWindow& m_window;
	MarioWorld m_marioworld;
	sf::Sprite gameOverBackground;
	sf::Sprite NextLevelBackground;
	sf::Clock dtClock;
	float deltaTime = 0;
	sf::Clock gameTime;
	std::vector<sf::Text> m_texts;
	std::string m_informations[OPTIONS] = { "Find the Flag Mario" , "Let's Go Mario ", "Good job, Mario Get ready for the next level!",
		"                        Level Paused\n\n     Press Enter to continue , if you \n    want to exit the game press Y"}; 
	bool musicOn;
};