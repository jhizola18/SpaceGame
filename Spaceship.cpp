#include "Spaceship.h"



Player_Ship::Player_Ship()
{
	gravity = 9.08f;
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
	float deltaF = GetFrameTime();
	point_Top.y -= speed * deltaF;
	point_Left.y -= speed * deltaF;
	point_Right.y -= speed * deltaF;
	gravity++;
}

void Player_Ship::gravityForward()
{
	float deltaF = GetFrameTime();
	point_Top.y -= gravity * deltaF;
	point_Left.y -= gravity * deltaF;
	point_Right.y -= gravity * deltaF;
}

void Player_Ship::moveBackward()
{
	float deltaB = GetFrameTime();
	point_Top.y += speed * deltaB;
	point_Left.y += speed * deltaB;
	point_Right.y += speed * deltaB;
	gravity--;
}

void Player_Ship::gravityBackward()
{
	float deltaB = GetFrameTime();
	point_Top.y -= gravity * deltaB;
	point_Left.y -= gravity * deltaB;
	point_Right.y -= gravity * deltaB;
}

void Player_Ship::gravityReset()
{
	if (IsKeyPressed(KEY_W))
	{
		gravity = 9.08f;
	}
	if (IsKeyPressed(KEY_S))
	{
		gravity = -9.08f;
	}
}
