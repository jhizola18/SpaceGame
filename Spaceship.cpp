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
//stop pre determining the position of where the bullets stored
Player_Ship::Bullet* Player_Ship::NewBullet()
{
	Bullet* thisBullet = new Bullet();
	thisBullet->data = 15;
	thisBullet->posX = NULL;
	thisBullet->posY = NULL;
	thisBullet->deadBullet = false;
	thisBullet->firedBullet = false;
	thisBullet->next = nullptr;
	thisBullet->prev = nullptr;
	thisBullet->color = WHITE;

	return thisBullet;
}

void Player_Ship::storeBullets()
{
	Bullet* thisBullet = NewBullet();
	thisBullet->next = firstBullet;
	thisBullet->prev = nullptr;
	firstBullet = thisBullet;
	//find use for the tail
	lastBullet = firstBullet;
	
}

void Player_Ship::reloadBullets()
{
	for (int i = 0; i < clipSize; ++i)
	{
		storeBullets();
	}
	Bullet* thisBullet = firstBullet;
	for (int i = 0; i < clipSize; ++i)
	{
		std::cout << thisBullet->data << " ";
	}
}

//fix this so that it moves and fits to the whole system code
void Player_Ship::updateBullets(float velocity, int posY)
{
	Bullet* thisBullet = firstBullet;
	
	/*while (thisBullet != nullptr)*/
	
		thisBullet->posY -= velocity;
		if (thisBullet->posY < GetScreenHeight())
		{
			thisBullet->deadBullet = true;
			
		}
		thisBullet = thisBullet->next;
}



void Player_Ship::renderBullets(int posY, int posX)
{
	Bullet* thisBullet = firstBullet;
	Bullet* deadBullet = nullptr;

	while (thisBullet != nullptr)
	{
		/*if (thisBullet->deadBullet == true)
		{
			deadBullet = thisBullet;
			thisBullet = thisBullet->next;
			if (firstBullet == deadBullet)
			{
				firstBullet = thisBullet;
				if (thisBullet != nullptr)
				{
					thisBullet->prev = nullptr;
				}
			}else {
				deadBullet->prev->next = thisBullet;
				if (thisBullet != nullptr)
				{
					thisBullet->prev = deadBullet->prev;
				}
			}
			if (lastBullet == deadBullet)
			{
				lastBullet = deadBullet->prev;
			}
			delete deadBullet;
		}
		else {*/
			//try to put a variable that will reset the value of the position Y
			//fix the spawning of the bullets;
			//Draw in a way that the bullet adjust to where the ship
			
			DrawRectangle(posX, posY, 5, 20, thisBullet->color);
			thisBullet = thisBullet->next;
		}
	
}

float Player_Ship::getVelocity()
{
	return 5.0f;
}

void Player_Ship::fireBullets(float velocity, int posY)
{
	updateBullets(velocity, posY);
}

