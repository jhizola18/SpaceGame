#pragma once
#include"raylib.h"
#include "unordered_map"

extern int magCount;
extern bool gameOver;
extern enum Game_State { Start_Menu, Gameplay ,Pause,Play ,Option, GameOver }game_state;
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
};
