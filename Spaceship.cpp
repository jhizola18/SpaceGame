#include "Spaceship.h"
#include <iostream>


Player_Ship::Player_Ship()
{
	gravity_Y = 9.08f;
	gravity_X = 0.0f;
	point_Top = {300, 720};
	point_Left = {280 , 750};
	point_Right = {320, 750};
	speed = 100.0f;
	firstBullet = nullptr;
	lastBullet = nullptr;
	clipSize = 7;
	reloadBullets();
}

void Player_Ship::Draw()
{
	//counterclockwise
	DrawTriangle(point_Top, point_Left, point_Right, BLUE);
}


//Figure out how to have applied gravity on all directions
void Player_Ship::moveForward()
{
	float deltaF = GetFrameTime();
	point_Top.y -= speed * deltaF;
	point_Left.y -= speed * deltaF;
	point_Right.y -= speed * deltaF;
	gravity_Y++;
}
void Player_Ship::gravityForward()
{
	float deltaF = GetFrameTime();
	point_Top.y -= gravity_Y * deltaF;
	point_Left.y -= gravity_Y * deltaF;
	point_Right.y -= gravity_Y * deltaF;
}

void Player_Ship::moveBackward()
{
	float deltaB = GetFrameTime();
	point_Top.y += speed * deltaB;
	point_Left.y += speed * deltaB;
	point_Right.y += speed * deltaB;
	gravity_Y--;
}
void Player_Ship::gravityBackward()
{
	float deltaB = GetFrameTime();
	point_Top.y -= gravity_Y * deltaB;
	point_Left.y -= gravity_Y * deltaB;
	point_Right.y -= gravity_Y * deltaB;
}


void Player_Ship::moveLeft()
{
	float deltaL = GetFrameTime();
	point_Top.x -= speed * deltaL;
	point_Left.x -= speed * deltaL;
	point_Right.x -= speed * deltaL;
	gravity_X++;
}

void Player_Ship::gravityLeft()
{
	float deltaL = GetFrameTime();
	point_Top.x -= gravity_X  * deltaL;
	point_Left.x -= gravity_X * deltaL;
	point_Right.x -= gravity_X * deltaL;
	
}


void Player_Ship::moveRight()
{
	float deltaR = GetFrameTime();
	point_Top.x += speed * deltaR;
	point_Left.x += speed * deltaR;
	point_Right.x += speed * deltaR;
	gravity_X--;
}

void Player_Ship::gravityRight()
{
	float deltaR = GetFrameTime();
	point_Top.x -= gravity_X * deltaR;
	point_Left.x -= gravity_X * deltaR;
	point_Right.x -= gravity_X * deltaR;
}


void Player_Ship::gravityReset()
{
	if (IsKeyPressed(KEY_W))
	{
		gravity_Y = 9.08f;
	}

	if (IsKeyPressed(KEY_S))
	{
		gravity_Y = -9.08f;
	}

	if (IsKeyPressed(KEY_A))
	{
		gravity_X = -9.08f;
	}

	if (IsKeyPressed(KEY_D))
	{
		gravity_X = 9.08f;
	}

}

Player_Ship::Bullet* Player_Ship::NewBullet(Bullet* firstBullet , float posX, float posY, int data)
{

	if (firstBullet == nullptr)
	{
		firstBullet = new Bullet;
		lastBullet = firstBullet;

		lastBullet->next = nullptr;
		lastBullet->prev = nullptr;
	}
	else {
		lastBullet->next = new Bullet;
		lastBullet->next->prev = lastBullet;

		lastBullet = lastBullet->next;
		lastBullet->next = nullptr;
	}
	lastBullet->data = data;
	lastBullet->posX = posX - (5 / 2);
	lastBullet->posY = posY;
	lastBullet->color = WHITE;
	lastBullet->deadBullet = false;
	lastBullet->firedBullet = false;
	
	return firstBullet;
}

void Player_Ship::reloadBullets()
{
	for (int i = 0; i < clipSize; ++i)
	{
		firstBullet = NewBullet(firstBullet ,point_Top.x, point_Top.y,15);
	}

	
}
//put a velocity parameter here!!!!
void Player_Ship::updateBullets()
{
	Bullet* thisBullet = firstBullet;
	
	while (thisBullet != nullptr)
	{
		thisBullet->posY -= 10;
		
		if (thisBullet->posY <= GetScreenHeight())
		{
			thisBullet->deadBullet = true;
			thisBullet = thisBullet->next;
		}
	}
}

//fix this so that it can render individual Rectangle
void Player_Ship::renderBullets()
{
	//firstBullet = NewBullet(firstBullet, point_Top.x, point_Top.y, 15);
	Bullet* thisBullet = firstBullet;
	Bullet* deadBullet = nullptr;

	while (thisBullet->next != nullptr)
	{
		thisBullet = thisBullet->next;
	}
	
	if (lastBullet->deadBullet == true)
	{
		deadBullet = lastBullet;
		lastBullet->prev->next = nullptr;
		delete deadBullet;
	}
	else {
		DrawRectangle(thisBullet->posX, thisBullet->posY, 5, 20, lastBullet->color);
		thisBullet = thisBullet->next;
	}
	
}

void Player_Ship::initialBullet()
{
	Bullet* thisBullet = firstBullet;

	while (thisBullet != nullptr)
	{
		thisBullet->posY -= 15;
		thisBullet = thisBullet->next;
	}
}

void Player_Ship::fireBullets()
{
	updateBullets();
}

