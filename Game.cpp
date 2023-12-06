#include "Game.h"

Game::Game()
{
	velocity = 0;
	positionX = ship.getPointTop().x;
	positionY = ship.getPointTop().y;
	keyPressed = false;
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
		positionX = ship.getPointTop().x;
		keyPressed = true;
		
	}
	
	if (keyPressed)
	{
			ship.fireBullets(ship.getVelocity(), positionY, positionX);
	}

}


void Game::Draw()
{
	
	if (IsKeyPressed(KEY_E))
	{
		keyPressed = true;
		
	}
	if (keyPressed)
	{
		ship.renderBullets();
	}
	

	
	ship.Draw();
}
