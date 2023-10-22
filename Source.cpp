#include "Window.h"
#include "Game.h"

int main()
{
	const int width = 600;
	const int height = 800;

	Window window{width, height, 74, "SpaceGame"};

	Game game = Game();

	while (!window.gameShouldClose())
	{
		game.userInput();
		BeginDrawing();
		ClearBackground(BLACK);
		game.Draw();
		EndDrawing();
	}

	return 0;
}