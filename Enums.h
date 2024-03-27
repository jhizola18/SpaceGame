#pragma once
#include"raylib.h"

extern int magCount;
extern bool gameOver;
extern enum Game_State { Start_Menu, Gameplay ,Pause, Option }game_state;

namespace varHolder
{
	const int clipSize();
	const int enemySize();
	const int enemyPool();
	const int collisionOffset();
	const int bulletOffset();
	
};
