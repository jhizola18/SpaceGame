#include "Game.h"

Game::Game()
{
	
}

void Game::userInput()
{
	if (IsKeyDown(KEY_W))
	{
		ship.moveForward();
		ship.gravityReset();
	}else {
		ship.gravityForward();
	}


	if (IsKeyDown(KEY_S))
	{
		ship.moveBackward();
		ship.gravityReset();
	}
	else {
		ship.gravityBackward();
	}


	if (IsKeyDown(KEY_A))
	{
		ship.moveLeft();
		ship.gravityReset();
		
	}else {
		ship.gravityLeft();
	}
	
	
	if (IsKeyDown(KEY_D))
	{
		ship.moveRight();
		ship.gravityReset();
		
	}else {
		ship.gravityRight();
	}
	
	if (IsKeyPressed(KEY_E))
	{
		ship.renderBullets();
	}
	else {
		gunFiring();
	}
	
}

void Game::gunFiring()
{
	ship.fireBullets();
}

void Game::Draw()
{
	ship.Draw();
}
