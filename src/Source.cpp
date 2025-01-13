#include "Window.h"
#include "Game.h"




int main()
{
	constexpr int width = 600;
	constexpr int height = 800;

	InitAudioDevice();

	Window window{ width, height, 74, "PEW PEW GAME" };
	Game game = Game();



	
	HideCursor();
	while (!window.gameShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLACK);
		game.MainGame();
		EndDrawing();
	}


	return 0;


}