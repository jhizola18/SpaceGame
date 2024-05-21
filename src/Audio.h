#pragma once
#include "raylib.h"


class Audio {
private:
	Music menu;
	Music In_Game;
	Sound Gameplay;
	Sound Dead;
	//Sound Explosion;
	Sound Pause;
	Sound Shooting;
	float vfx_vol;
	float bgm_vol;

public:
	Audio();
	~Audio()noexcept;

	Music soundMenu();
	void soundStart();
	void soundGameOver();
	void soundPause();
	Music soundInGame();
	void soundShooting();
	//fix sound settings
	void soundLevel();
	float& get_Vfx_vol();
	float& get_bgm_vol();

};