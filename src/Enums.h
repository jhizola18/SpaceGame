#pragma once
#include"raylib.h"
#include "unordered_map"
#include "Vector"

extern int magCount;
extern bool gameOver;
extern enum Game_State { Start_Menu, Gameplay ,Pause,Play ,Option, GameOver }game_state;
extern enum Level_State {Level1, Level2, Level3}level_state;
extern bool pause;
extern int Destroyed;
extern int HighScore;

namespace varHolder
{
	const int clipSize();
	const int enemySize();
	const int enemyPool();
	const int collisionOffset();
	const int bulletOffset();
	Vector2 cursorPosition();
	std::vector<const char*> ship_Colors();
};
