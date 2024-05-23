#include "Window.h"
#include "Game.h"
#include "emscripten.h"



int main()
{
	constexpr int width = 600;
	constexpr int height = 800;

	InitAudioDevice();

	Window window{ width, height, 74, "SpaceGame" };
	Game game = Game();


#if defined(PLATFORM_WEB)
	emscripten_set_main_loop(Game.MainGame(), 60, 1);
#else
	
	HideCursor();
	while (!window.gameShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLACK);
		game.MainGame();
		EndDrawing();
	}

#endif
	return 0;


}