#pragma once
#include "raylib.h"
#include <string>
#include <assert.h>
#include "Audio.h"

class Window {
public:
	Window(int width, int height, int fps, std::string title);
	~Window() noexcept;
	bool gameShouldClose();

};