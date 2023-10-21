#include "Window.h"

int main()
{
	const int width = 600;
	const int height = 800;

	Window window{width, height, 60, "SpaceGame"};

	while (!window.gameShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLACK);
		EndDrawing();
	}

	return 0;
}