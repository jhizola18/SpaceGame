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

public:
	Audio();
	~Audio()noexcept;

	Music soundMenu();
	void soundStart();
	void soundGameOver();
	void soundPause();
	Music soundInGame();
	void soundShooting();
};