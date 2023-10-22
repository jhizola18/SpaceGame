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
}

void Game::Draw()
{
	ship.Draw();
}
