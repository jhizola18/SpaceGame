#include "Window.h"
#include "Game.h"
#include "MenuManager.h"
#include "Enums.h"

Game_State game_state = Start_Menu;
Game_State prev_state = game_state;
int main()
{
	constexpr int width = 600;
	constexpr int height = 800;

	Window window{ width, height, 74, "SpaceGame" };
	Menu menu = Menu();
	Game game = Game();
	
	while (!window.gameShouldClose())
	{
		
		switch (game_state)
		{
		case Start_Menu:
			BeginDrawing();
			menu.MainMenu();
			if (menu.MenuBtn())
			{
				game_state = Gameplay;
			}
			if (menu.OptionBtn())
			{
				game_state = Option;
			}
			EndDrawing();
			break;
		case Gameplay:
			game.userInput();
			BeginDrawing();
			game.gameMechanics();
			ClearBackground(BLACK);
			if (menu.BackBtn())
			{
				game_state = prev_state;
			}
			game.Draw();
			EndDrawing();
			break;
		case Option:
			BeginDrawing();
			ClearBackground(BLUE);
			if (menu.BackBtn())
			{
				game_state = prev_state;
			}
			
			EndDrawing();

		default:
			break;
		}
		
	}


	return 0;
}