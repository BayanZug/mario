#pragma once
#include "Utilities.h"
#include "Resources.h"
#include "Controller.h"
#include <string>
#include "Utilities.h"
//---------------------------------------------------------------
//This is a Menu class, where the game stars where there many 
// choices you can get for sounds,music, difficault &
// here you can get instrction to the game
//----------------------------------------------------------------
class Menu
{
public:
  Menu();
  ~Menu() = default;
  void run();
  void draw(sf::RenderWindow& window);
  void select();
  void setMenu();
  void execCommand(options option);
  void readInstructions();
  void secondMenu(const sf::Vector2f &);
private:
  sf::RenderWindow window;
  sf::Sprite m_background;
  std::vector<sf::Text> menu;
  std::vector<sf::Text> m_options;
  std::string m_optionsStrings[NUM_OF_OPTIONS] = { "Play Game", "Options","Instructions","Exit" };
  std::string m_menuOptions[6] = {  "Sound Effects: ON" ,  "Music: ON","Difficulty: Easy", "Return to the menu",  "Music: OFF", "Sound Effects: OFF" };
  std::string difficultyString[2] = { "Difficulty: Easy","Difficulty: Hard " };
  std::string instructions ="                                                           Mario Game Insructions:\n"
		"                     The Goal of mario is to finish the levels without losing his lives.\n"
		"                                        And Now Let's learn  who to control the game :\n"
	    "                 * To move Mario to the Right or to the Left press the Right/Left keys\n"
		"                 * Mario can also jump, to jump him Press SPACE\n"
	    "                 * Mario can hurt his enemies by jumping on them or attacking by \n"
		"                   pressing 'A',BUT!don't jump on the spiny enemies because they're spiky\n"
		"                 * Gathering the coins give mario blood heart bonus,each star increase\n                       mario lives by one\n"
		"                 * To pause game press esc key\n\n"
		"                                            GOOD LUCK IN YOUR ADVANTURES \n"
		"                                            press enter to go back to the menu      ";
  sf::Text m_instructions;
  sf::Sound backgroundMusic;
  sf::Sound clickSound;
  int m_difficault;
  bool gameOver = false;
  bool isOptions = false;
  bool m_sound;
  bool m_music;
};
