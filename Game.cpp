#include "Game.h"

Game::Game()
{
	velocity = 0;
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
		velocity = ship.getVelocity();
		positionY = ship.getPointTop().y;
	}
	else {
		ship.fireBullets(velocity, positionY);
	}
		
}


void Game::Draw()
{
	
	if (IsKeyPressed(KEY_E))
	{
		positionX = ship.getPointTop().x;
		positionY = ship.getPointTop().y;
	}
	ship.renderBullets(positionX, positionY);
	ship.Draw();
}
