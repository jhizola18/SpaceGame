#include "Window.h"
#include "Game.h"
#include "MenuManager.h"


#if defined(PLATFORM_WEB)
	#include <emscripten/emscripten.h>
#endif

bool pause = false;
Game_State game_state = Start_Menu;
Game_State prev_state = game_state;




int main()
{
	constexpr int width = 600;
	constexpr int height = 800;

	//Audio* audio = new Audio{};
	Audio* audio = new Audio();
	Window window{ width, height, 74, "SpaceGame" };
	Player_Ship ship{};

	Menu menu = Menu();
	Game game = Game();
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
			game.userInput();
			game.gameMechanics();
			menu.Player_Score();
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
				game.resetGame();
				audio->soundGameOver();
				game_state = GameOver;
			}
			menu.showScore();
			game.Draw(menu.colorSettings(ship));
			break;
		case Pause:
			if (menu.PlayBtn())
			{
				audio->soundPause();
				pause = false;
				game_state = Gameplay;
			};
			menu.showScore();
			game.Draw(menu.colorSettings(ship));
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
			game.resetGame();
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

		EndDrawing();
		

	}
	delete audio;
	audio = NULL;

	return 0;
}