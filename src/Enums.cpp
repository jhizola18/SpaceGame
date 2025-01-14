#include "Enums.h"



const int varHolder::clipSize()
{
	return 20;
}

const int varHolder::enemySize()
{
	return 5;
}

const int varHolder::enemyPool()
{
	return 15;
}

const int varHolder::collisionOffset()
{
	return 15;
}

const int varHolder::bulletOffset()
{
	return 15;
}

Vector2 varHolder::cursorPosition()
{
	return{GetMousePosition().x, GetMousePosition().y};
}

std::vector<Color> varHolder::ship_colors()
{
	return {BLUE, RED, YELLOW, GREEN, BROWN, PINK};
}

//Draw a ship for the remaining colors
std::vector<const char*> varHolder::ship_Colors()
{
	return {"Image/ship_blue.png","Image/ship_red.png","Image/ship_yellow.png","Image/ship_green.png", "Image/ship_brown.png", "Image/ship_pink.png" };
}




