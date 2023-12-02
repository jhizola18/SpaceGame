#pragma once
#include "Spaceship.h"

class Game {
private:
	Player_Ship ship = Player_Ship();
	bool keyPressed;
public:
	Game();
	void userInput();
	void Draw();

	int velocity;
	int positionX;
	int positionY;

	
};