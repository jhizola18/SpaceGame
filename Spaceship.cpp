#include "Spaceship.h"
#include <iostream>
#include "Enums.h"

bool bulletActive;
int magCount;

Player_Ship::Player_Ship()
{
	gravity_Y = 9.08f;
	gravity_X = 0.0f;
	point_Top = {300, 720};
	point_Left = {280 , 750};
	point_Right = { 320, 750 };
	firstBullet = nullptr;
	lastBullet = nullptr;
	thisBullet = nullptr;
	deadBullet = nullptr;
	speed = 100.0f;
	bulletVelocity = 0;
	reloadBullets();
}

Vector2 Player_Ship::getPointTop()
{
	return point_Top;
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
	int Pressed = GetKeyPressed();
	switch(Pressed){
	case KEY_W:
		gravity_Y = 9.08f;
		break;
	case KEY_S:
		gravity_Y = -9.08f;
		break;
	case KEY_A:
		gravity_X = -9.08f;
		break;
	case KEY_D:
		gravity_X = 9.08f;
		break;
	default:
		break;
	}
}

Player_Ship::Bullet* Player_Ship::NewBullet()
{
	Bullet* NewBullet = new Bullet();
	NewBullet->rec = {0, 0, 5, 10};
	NewBullet->data = 15;
	NewBullet->bulletSpeed = 5;
	NewBullet->next = nullptr;
	NewBullet->prev = nullptr;
	NewBullet->color = WHITE;

	return NewBullet;
}

void Player_Ship::storeBullets()
{
	thisBullet = NewBullet();
	if (firstBullet == nullptr)
	{
		thisBullet->next = firstBullet;
		firstBullet = thisBullet;
		lastBullet = firstBullet;
		magCount++;
	}
	else {
		Bullet* tracker = firstBullet;
		while (tracker->next != lastBullet->next)
		{
			tracker = tracker->next;
		}
		lastBullet = thisBullet;
		lastBullet->prev = tracker;
		tracker->next = lastBullet;
		lastBullet->next = firstBullet;
		magCount++;
	}
}


void Player_Ship::reloadBullets()
{
	storeBullets();
	Bullet* thisBullet = firstBullet;
	
	while (thisBullet != lastBullet)
	{
		std::cout << thisBullet->data << " ";
		thisBullet = thisBullet->next;
	}
	std::cout << "Linked list count content->  " << magCount << " ";
	
}


void Player_Ship::updateBullets(int posY, int posX)
{
	thisBullet = lastBullet;
	while (thisBullet != firstBullet)
	{
		if (thisBullet->rec.x == 0 && thisBullet->rec.y == 0)
		{
			thisBullet->rec.y = posY;
			thisBullet->rec.x = posX;
		}
		thisBullet->data = 1;
		thisBullet->rec.y -= thisBullet->bulletSpeed;
		thisBullet = thisBullet->prev;
	}
	
}

bool Player_Ship::isDead()
{
	if (lastBullet->rec.y < 0)
	{
		return true;
	}
	else {
		return false;
	}
}

bool Player_Ship::isActive()
{
	if (lastBullet->rec.y >= point_Top.y)
	{
		return true;
	}
	else {
		return false;
	}
}

void Player_Ship::renderBullets()
{
	thisBullet = lastBullet;
	while (thisBullet != firstBullet)
	{
		DrawRectangleRec(thisBullet->rec, thisBullet->color);
		thisBullet = thisBullet->prev;
	}
	/**/
	if (magCount == 7)
	{
		magCount = 6;
		deleteBullet();
	}
}

void Player_Ship::deleteBullet()
{
	thisBullet = firstBullet;
	firstBullet = thisBullet->next;
	deadBullet = thisBullet;
	delete deadBullet;
}
	

void Player_Ship::fireBullets( int posY, int posX)
{
	updateBullets( posY, posX);
}
