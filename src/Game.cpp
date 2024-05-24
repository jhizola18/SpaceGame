#include "Game.h"
#include "enums.h"


using namespace varHolder;

bool pause = false;
Game_State game_state = Start_Menu;
Game_State prev_state = game_state;

int index = 0;

Game::Game()
	:
	bullet(),
	enemy(),
	ship()
{
	positionX = ship.getPointTop().x;
	positionY = ship.getPointTop().y;
	velocity = 0;
}

Game::~Game() noexcept
{
	delete audio;
	audio = NULL;
}

void Game::resetGame()
{
	ship.gravityReset();
	enemy.resetFullEnemy();
	ship.ResetShip();
	bullet.resetAllBullet();
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
		positionY = ship.getPointTop().y;
		positionX = ship.getPointTop().x;
		bullet.updateBullet(positionX, positionY, bullet.getBullet());
	}
	else {
		bullet.bulletMovement(varHolder::cursorPosition(), 59.0f);
	}
	
}

void Game::Draw(int colortype)
{
	bullet.drawBullet();
	enemy.Draw();
	ship.Draw(colortype);
}


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

void Game::MainGame()
{
	menu.Background(0, 0, WHITE);
	menu.DrawCursor();
	switch (game_state)
	{
	case Start_Menu:
		UpdateMusicStream(audio->soundMenu());
		if (menu.MenuBtn())
		{
			audio->soundStart();
			game_state = Gameplay;
		};
		if (menu.OptionBtn())
		{
			audio->soundPause();
			game_state = Option;
		};
		break;
	case Gameplay:
		UpdateMusicStream(audio->soundInGame());
		userInput();
		gameMechanics();
		menu.Player_Score();
		menu.healthbar(ship.getPointLeft().x, ship.getPointLeft().y, ship.getHealth());
		ClearBackground(BLACK);
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			audio->soundShooting();
		}
		if (menu.PauseBtn())
		{
			audio->soundPause();
			game_state = Pause;
			pause = true;
		};
		if (gameOver)
		{
			resetGame();
			audio->soundGameOver();
			game_state = GameOver;
		}
		menu.showScore();
		Draw(menu.colorSettings(ship));
		break;
	case Pause:
		if (menu.PlayBtn())
		{
			audio->soundPause();
			pause = false;
			game_state = Gameplay;
		};
		menu.showScore();
		Draw(menu.colorSettings(ship));
		break;
	case Option:

		audio->soundLevel();
		menu.soundSettings(audio->get_Vfx_vol(), audio->get_bgm_vol());

		menu.colorSettings(ship);
		menu.colorSettingsGUI(ship);
		if (menu.BackBtn())
		{
			audio->soundPause();
			game_state = prev_state;
		};

		break;
	case GameOver:
		menu.showScore();
		resetGame();
		if (menu.Replay())
		{
			audio->soundPause();
			game_state = Gameplay;
			gameOver = false;
			Destroyed = 0;

		}
		if (menu.MenuBackBtn())
		{
			audio->soundPause();
			game_state = Start_Menu;
			gameOver = false;
			Destroyed = 0;
		}
		break;
	default:
		break;
	}
}

