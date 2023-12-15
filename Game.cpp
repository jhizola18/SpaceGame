#include "Game.h"

bool keyPressed = false;
bool isBulletFired = false;

Game::Game()
{
	velocity = 0;
	positionX = ship.getPointTop().x;
	positionY = ship.getPointTop().y;
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
	//PRIORITIZE::Fix so that the bullet change dynamically.
	//ORIGINAL FIXED::Original fix is we put value on a bullet if the fire button is click
	if (IsKeyPressed(KEY_E))
	{
		
		velocity = ship.getVelocity();
		positionY = ship.getPointTop().y;
		positionX = ship.getPointTop().x;
		keyPressed = true;
		ship.checkingStruct();
	}
	if (keyPressed)
	{
			ship.fireBullets(ship.getVelocity(), positionY, positionX);
			isBulletFired = true;
	}
}


void Game::Draw()
{
	
	if (isBulletFired)
	{
		ship.renderBullets();
	}
	ship.Draw();
}
