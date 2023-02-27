#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <string>
enum pictures_t { menu1_background, nextlevel_background, gameover_background,};
enum class fontType { menufont, gameFont };
enum class sound_t {
sound_BottonClick,
sound_mushroom,
sound_gift,
sound_star,
sound_goomba,
sound_mariojump,
sound_firstLevel,
sound_secondLevel,
sound_3level,
sound_gameover,
sound_marioattak,
sound_mariohurt,
sound_menu,
sound_mariofall,
sound_boo};
enum class options { Start_Game, Options, game_instructions, exit };
enum class objectOption { block, background, gift };
enum class menuOptions { sound, music, difficulty, backToMenu };
enum class difficulty_t { easy, hard };
enum class animationType { moving, jumping, standing, attacking, hanging, rotating, defeating, moving_up, flying, injured };
enum class giftType { _coin, _star, _mashroom, _flag };
enum class direction { Left, Right };
#define WORLD_MAP "level.txt" 
enum{findFlag,runMessage,passLevel,pauseMessage};
const float MARIO_SPEED = 100.0f;
const float TURTLE_SPEED = 15.0f;
const float GOOMBA_SPEED = 30.0f;
const float BOO_SPEED = 35.0f;
enum class extraAccesorios_type_t
{_tree,_ftree,_tree1,_tree2,_tree3, _tree4, _tree5};
enum class block_type_t
{topLeft,ground,topRight,left_wall,in_floor,
right_wall,botLeft,bone,botRight,left_island,
mid_island,right_island
};
const int OPTIONS = 4 ;
const int RAPIDTY = 50;
const int END_LIMIT = 30;
const int NEXT_FRAME = 84;
const int FRAME_LIMIT = 30;
const int JUMP_EFFECT = 25;
const int FIVE = 5;
const int STEP = 12;
const int VIEW_WIDTH = 800;
const int VIEW_HEIGHT = 500;
const int JUMP_DISTANCE = 30;
const int LOCATION_LIM = 300;
const int TWO_DIRECTIONS = 2;
const int NUM_OF_OPTIONS = 4;
const int GAME_FONT_SIZE = 40;
const int DIFFICULT_LEVEL = 2;
const int MENU_FONT_SIZE = 100;
const int FONTMENUSAPACE = 90;
const int WINDOW_SIZE_X = 640 * 2;
const int WINDOW_SIZE_Y = 480 * 2;
const int WORLD_BLOCK_SIZE_X = 33;
const int WORLD_BLOCK_SIZE_Y = 33;
const int NUM_OF_ROTATION_ANIMATIONS = 6;
