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
	return {BLUE, RED, YELLOW, GREEN, BROWN};
}




