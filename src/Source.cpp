#include "Window.h"
#include "Game.h"
#include "MenuManager.h"


bool pause = false;
Game_State game_state = Start_Menu;
Game_State prev_state = game_state;

int main()
{
	constexpr int width = 600;
	constexpr int height = 800;

	Window window{ width, height, 74, "SpaceGame" };
	
	Menu menu = Menu();
	Game game = Game();
	//Refactor the Switch Statement for pause play find a better solution
	HideCursor();
	
	while (!window.gameShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLACK);
		menu.Background(0,0,WHITE);
		menu.DrawCursor();
		switch (game_state)
		{
		case Start_Menu:

			if (menu.MenuBtn())
			{
				game_state = Gameplay;
			};
			if (menu.OptionBtn())
			{
				game_state = Option;
			};
			break;
		case Gameplay:
			game.userInput();
			game.gameMechanics();
			menu.Player_Score();
			ClearBackground(BLACK);
			if (menu.PauseBtn())
			{
				game_state = Pause;
				pause = true;
			};
			if (gameOver)
			{
				game.resetGame();
				game_state = GameOver;
			}
			menu.showScore();
			game.Draw();
			break;
		case Pause:
			
			if (menu.PlayBtn())
			{
				pause = false;
				game_state = Gameplay;
			};
			menu.showScore();
			game.Draw();
			break;
		case Option:
			
			if (menu.BackBtn())
			{
				game_state = prev_state;
			};
			
			break;
		case GameOver:
			menu.showScore();
			game.resetGame();
			if (menu.Replay())
			{
				game_state = Gameplay;
				gameOver = false;
				Destroyed = 0;
				
			}
			if (menu.MenuBackBtn())
			{
				game_state = Start_Menu;
				gameOver = false;
				Destroyed = 0;
			}
			break;
		default:
			break;
		}

		EndDrawing();
	}
	

	return 0;
}