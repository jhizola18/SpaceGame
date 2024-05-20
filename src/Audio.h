#pragma once
#include "raylib.h"


class Audio {
private:
	Music menu;
	Sound Gameplay;
	Sound Dead;
	Sound Explosion;

	float timePlayed;
public:
	Audio();
	~Audio()noexcept;

	Music soundMenu();
	void soundStart();
	void soundGameOver();
};