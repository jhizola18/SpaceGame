#pragma once
#include "raylib.h"



class Menu {

public:
	Menu();
	~Menu();

	void MainMenu();
	bool MenuBtn();
	bool OptionBtn();
	bool BackBtn();
};