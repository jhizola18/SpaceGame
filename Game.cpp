#include "Game.h"

Game::Game()
{
}

void Game::userInput()
{
	if (IsKeyDown(KEY_W))
	{
		ship.moveForward();
	}
	if (IsKeyDown(KEY_S))
	{
		ship.moveBackward();
	}
}

void Game::Draw()
{
	ship.Draw();
}
