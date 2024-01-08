#include "Game.h"

int index = 0;

Game::Game()
{
	positionX = ship.getPointTop().x;
	positionY = ship.getPointTop().y;
	velocity = 0;
	
}

void Game::userInput()
{
	if (IsKeyDown(KEY_W))
	{
		ship.moveForward();
		ship.gravityReset();
	}
	else {
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

	}
	else {
		ship.gravityLeft();
	}


	if (IsKeyDown(KEY_D))
	{
		ship.moveRight();
		ship.gravityReset();

	}
	else {
		ship.gravityRight();
	}

	positionY = ship.getPointTop().y;
	positionX = ship.getPointTop().x;
	if (IsKeyPressed(KEY_E))
	{	
		ship.reloadBullets();
	}
	else {
		
		ship.fireBullets(positionY, positionX);
	}
}

void Game::Draw()
{
	enemy.Draw();
	ship.renderBullets();
	ship.Draw();
}

void Game::gameMechanics()
{
	enemy.enemyUpdate();
	collision.check_collision(enemy, ship);
}
