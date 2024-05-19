#pragma once
#include "raylib.h"


class Audio {
private:
	Music menu;
	Sound Gameplay;
	Sound Dead;
	Sound Explosion;
public:
	Audio();
	~Audio()noexcept;

	Music soundMenu();
};