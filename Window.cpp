#include "Window.h"


Window::Window(int width, int height, int fps, std::string title)
{
	assert(!GetWindowHandle());
	InitWindow(width, height, title.c_str());
	SetTargetFPS(fps);
}

Window::~Window() noexcept
{
	assert(GetWindowHandle());
	CloseWindow();
}

bool Window::gameShouldClose()
{
	assert(GetWindowHandle());
	return WindowShouldClose();
}

