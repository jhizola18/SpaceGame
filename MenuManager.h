#pragma once
#include "raylib.h"



class Menu {
private:
	Texture2D background;

public:
	Menu();
	~Menu();

	void MainMenu();
	bool MenuBtn();
	bool OptionBtn();
	bool BackBtn();
	bool PauseBtn();
	bool PlayBtn();
	void Background(int posx, int posy, Color tint);
};