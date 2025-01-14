#pragma once
#include "raylib.h"
#include "Spaceship.h"


class Menu {
private:
	Player_Ship ship = Player_Ship();
	Texture2D background;
	std::vector<const char*> colored;
	Image title;
	Texture2D titleAnim;
	Vector2 PositionTitle;
	float fontsize;

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
	void healthbar(float posx, float posy,  float& health);

	void soundSettings(float& vfx_vol, float& bgm_vol);
	int colorSettings(Player_Ship& ship);
	void colorSettingsGUI(Player_Ship& ship);


};