#pragma once
#include "Spaceship.h"
#include "Enums.h"



class Game {
private:
	Player_Ship ship = Player_Ship();
	//Trigger triggerMain;
	

public:
	Game();
	void userInput();
	void Draw();

	int velocity;
	int positionY;
	int positionX;
};