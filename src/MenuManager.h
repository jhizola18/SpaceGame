#pragma once
#include "raylib.h"


class Menu {
private:
	Texture2D background;

public:
	Menu();
	~Menu();


	void DrawCursor();
	void MainMenu();
	bool MenuBtn();
	bool MenuBackBtn();
	bool OptionBtn();
	bool BackBtn();
	bool PauseBtn();
	bool PlayBtn();
	bool Replay();
	void Background(int posx, int posy, Color tint);
	void Player_Score();
	void showScore();

	void soundSettings(float& vfx_vol, float& bgm_vol);

	
};