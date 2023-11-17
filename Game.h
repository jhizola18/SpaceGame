#pragma once
#include "Spaceship.h"

class Game {
private:
	Player_Ship ship = Player_Ship();

public:
	Game();
	void userInput();
	void Draw();
	void gunFiring();
};