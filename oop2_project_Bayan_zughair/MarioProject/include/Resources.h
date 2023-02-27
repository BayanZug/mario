#pragma once
#include "Utilities.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
//--------------------------------------------------------
//This is a Resources class where there singletone to get 
// all the resourses of the game(png,font,sound)
//----------------------------------------------------------
class Resources
{
public:
	~Resources();
	sf::Texture& getheartthmario();
	sf::Texture& getgiftTextures();
	sf::Texture& gethealtharmario();
	sf::Texture& getgoombaTextures();
	sf::Texture& getMarioTextures();
	sf::Texture& getturtleTextures();
	sf::Font& getFont(fontType type);
	static Resources& loadResources();
	sf::Texture& getbooTextures();
	sf::Texture& getspinyTextures();
	sf::Texture& getTexture(pictures_t type);
	std::vector<sf::Texture>& getBackground();
	sf::Texture& getWorldTexture(int worldNumber);
	std::vector<sf::IntRect>& getExtraAccesorios(int worldNum);
	std::vector<sf::IntRect>& getWorldBlocks(int worldNumber);
	std::vector<sf::IntRect>& getFlag() { return m_flagRect; }
	std::vector<sf::IntRect>& getStar() { return m_starRect; }
	std::vector<sf::IntRect>& getMashroom() { return m_mashroomRect; }
	std::vector<sf::IntRect>& getMarioStanding() { return m_marioStandingRect; }
	std::vector<sf::IntRect>& getCoin() { return m_coinRect; }
	std::vector<sf::IntRect>& getmarioDataheart() { return m_mariodataeRect; }
	std::vector<sf::IntRect>& getmariohealth() { return m_mariohealthdataRect; }
	std::vector<sf::IntRect>& getMarioMovingRect() { return m_marioMovingRect; }
	std::vector<sf::IntRect>& getMarioJumpingRect() { return m_marioJumpinggRect; }
	std::vector<sf::IntRect>& getgoombaWalkingRect() { return  m_goomba_walking; }
	std::vector<sf::IntRect>& getgoombaJumpingRect() { return	m_goomba_jump; }
	std::vector<sf::IntRect>& getMarioGetHeartRect() { return m_mariogetheartRect; }
	std::vector<sf::IntRect>& getMarioRotationRect() { return m_marioRotatingRect; }
	std::vector<sf::IntRect>& getgoombaRotationRect() { return  m_goomba_rotation; }
	std::vector<sf::IntRect>& getMarioAttackingRect() { return m_marioAttackingRect; }
	std::vector<sf::IntRect>& getgoombastandingRect() { return m_goomba_standindRect; }
	std::vector<sf::IntRect>& getgoombasattakingRect() { return m_goomba_attakRect; }
	std::vector<sf::IntRect>& getgoombadefeatingRect() { return	m_goomba_defeating; }
	std::vector<sf::IntRect>& getturtlestandingRect() { return m_turtle_standindRect; }
	std::vector<sf::IntRect>& getbooflyingRect() { return m_boo_flyingRect; }
	std::vector<sf::IntRect>& getbootwalkingRect() { return m_boo_walkindRect; }
	sf::SoundBuffer& getSoundBuffer(sound_t soundType) { return m_sounds[(int)soundType]; }
	std::vector<sf::IntRect>& getturtlewalkingingRect() { return m_turtle_walkingRect; }
	std::vector<sf::IntRect>& getspinyrotatingRect() { return m_spiny_rotatingingRect; }
	std::vector<sf::IntRect>& getturtlesdefeatingRect() { return m_turtle_defeatdingRect; }
	std::vector<sf::IntRect>& getbootstandingRect() { return m_boo_standindRect; }
	std::vector<sf::IntRect>& getvuelturedefeatingRect() { return m_boo_deafitindRect; }
	std::vector<sf::IntRect>& getbootmoving_up_Rect() { return m_boo_moveupdRect; }
	std::vector<sf::IntRect>& getspinywalkingingRect() { return m_spiny_walkingRect; }
private:
	Resources();
	Resources(const Resources&) = default;
	Resources& operator=(const Resources&) = default;

	//game object's textures
	sf::Texture supermario;
	sf::Texture gift;
	sf::Texture goomba;
	sf::Texture	turtle;
	sf::Texture boo;
	sf::Texture datamario;
	sf::Texture spiny;
	sf::Texture heartbarmario;
	//base vector textures
	std::vector<sf::Font> m_fonts;
	std::vector<sf::Image> m_images;
	std::vector<sf::SoundBuffer> m_sounds;
	std::vector<sf::Texture> m_textures;
	std::vector<sf::IntRect> m_marioMovingRect;
	std::vector<sf::IntRect> m_marioStandingRect;
	std::vector<sf::IntRect> m_marioRotatingRect;
	std::vector<sf::IntRect> m_mariogetheartRect;
	std::vector<sf::IntRect> m_mariodataeRect;
	std::vector<sf::IntRect> m_marioAttackingRect;
	std::vector<sf::IntRect> m_marioJumpinggRect;
	std::vector<sf::IntRect> m_mariohealthdataRect;
	std::vector<sf::IntRect>  m_coinRect, m_starRect, m_mashroomRect, m_flagRect;

	//boo's textures
	std::vector<sf::IntRect> m_boo_standindRect;
	std::vector<sf::IntRect> m_boo_walkindRect;
	std::vector<sf::IntRect> m_boo_deafitindRect;
	std::vector<sf::IntRect> m_boo_moveupdRect;
	std::vector<sf::IntRect> m_boo_flyingRect;

	//-Goomba's textures
	std::vector<sf::IntRect> m_goomba_standindRect;
	std::vector<sf::IntRect> m_goomba_attakRect;
	std::vector<sf::IntRect> m_goomba_defeating;
	std::vector<sf::IntRect> m_goomba_jump;
	std::vector<sf::IntRect> m_goomba_rotation;
	std::vector<sf::IntRect> m_goomba_walking;
	//_spiny's textures-
	std::vector<sf::IntRect> m_spiny_walkingRect;
	std::vector<sf::IntRect> m_spiny_rotatingingRect;
	//-turtle's textures
	std::vector<sf::IntRect> m_turtle_walkingRect;
	std::vector<sf::IntRect> m_turtle_standindRect;
	std::vector<sf::IntRect> m_turtle_defeatdingRect;
	//_World1Rect's textures
	std::vector<sf::IntRect> m_World1Rect;
	std::vector<sf::IntRect> m_World2Rect;
	std::vector<sf::IntRect> m_World3Rect;
	//--_world1ground's textures-
	sf::Texture world1Ground;
	sf::Texture world2Ground;
	sf::Texture world3Ground;
	//_m_world1ExtraAccesorios's textures
	std::vector<sf::IntRect> m_world1ExtraAccesorios;
	std::vector<sf::IntRect> m_world2ExtraAccesorios;
	std::vector<sf::IntRect> m_world3ExtraAccesorios;
	std::vector < sf::Texture> backgrounds;
};