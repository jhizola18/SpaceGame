#include "Game.h"
#include "enums.h"

using namespace varHolder;

int index = 0;



Game::Game()
	:
	bullet()
{
	positionX = ship.getPointTop().x;
	positionY = ship.getPointTop().y;
	velocity = 0;
}

Game::~Game() noexcept
{
	enemy.~EnemyManager();
	ship.~Player_Ship();
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



	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		//float new_X = ((ship.getPointTop().x + ship.getPointRight().x + ship.getPointLeft().x) / 3.0f);
		//float new_Y = ((ship.getPointTop().y + ship.getPointRight().y + ship.getPointLeft().y) / 3.0f);
		positionY = ship.getPointTop().y;
		positionX = ship.getPointTop().x;
		bullet.updateBullet(positionX, positionY, bullet.getBullet());
	}
	else {
		bullet.bulletMovement(varHolder::cursorPosition(), 59.0f);
	}

	if (IsCursorOnScreen())
	{
		ship.rotationShip();
	}
	
}

void Game::Draw()
{
	bullet.drawBullet();
	enemy.Draw();
	ship.Draw();
}
//Create a mechanics for gaming
void Game::gameMechanics()
{
	if (gameOver == true)
	{
		enemy.resetFullEnemy();
		ship.ResetShip();
	}
	else {
		enemy.enemyUpdate(ship);
		collision.check_collision(enemy, bullet, ship);
	}
}
