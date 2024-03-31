#pragma once
#include"raylib.h"

extern int magCount;
extern bool gameOver;
extern enum Game_State { Start_Menu, Gameplay ,Pause,Play ,Option }game_state;
extern bool pause;
namespace varHolder
{
	const int clipSize();
	const int enemySize();
	const int enemyPool();
	const int collisionOffset();
	const int bulletOffset();
	
};
