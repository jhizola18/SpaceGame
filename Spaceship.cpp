#include "Spaceship.h"

Player_Ship::Player_Ship()
{
	point_Top = {300, 720};
	point_Left = {280 , 750};
	point_Right = {320, 750};
	speed = 100.0f;
}

void Player_Ship::Draw()
{
	//counterclockwise
	DrawTriangle(point_Top, point_Left, point_Right, BLUE);
}


void Player_Ship::moveForward()
{
	point_Top.y -= speed * GetFrameTime();
	point_Left.y -= speed * GetFrameTime();
	point_Right.y -= speed * GetFrameTime();
}

void Player_Ship::moveBackward()
{
	point_Top.y += speed * GetFrameTime();
	point_Left.y += speed * GetFrameTime();
	point_Right.y += speed * GetFrameTime();
}
