#include "Player.h"



void Player::playerActions()
{
	movePlayer();
	playerJump();
	movePlayerScreen();
	playerCollision();
}


void Player::playerJump()
{
	dy += 0.3;
	playerPosition.y += dy;
}

void Player::movePlayerScreen()
{
	int num = 0;

	if (playerPosition.y <distinct)
		for (int i = 0; i < 10; i++)
		{
			playerPosition.y = distinct;
			platformPosition[i].y = platformPosition[i].y - dy;


			if (platformPosition[i].y > height-13)
			{
				platformPosition[i].y = num;
				num += 50;
				platformPosition[i].x = rand() % (width -50);
			}
		}
}


void Player::playerCollision()
{
	//Fixed values based on size of picture
	for (int i = 0; i < 10; i++)
		if ((playerPosition.x + 50 > platformPosition[i].x) &&
			(playerPosition.x + 20 < platformPosition[i].x + 68)
			&& (playerPosition.y + 70 > platformPosition[i].y)
			&& (playerPosition.y + 70 < platformPosition[i].y + 14)
			&& (dy > 0))
		{
			dy = -10;
			score += 1;
		}
}

void Player::movePlayer()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{

		if ((playerPosition.x += 5) + 50 <= width)
			playerPosition.x += 5;
		else
			playerPosition.x = -20;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if ((playerPosition.x -= 5) > 0)
			playerPosition.x -= 5;
		else
			playerPosition.x = width;
	}
}

int Player::getPlayerScore()
{
	return this->score;
}


Player::Player(Point* p)
{
	this->platformPosition = p;
}
void Player::setInfo(int width, int height, int distinct, int deltaY)
{
	this->width = width;
	this->height = height;
	this->distinct = distinct;
	this->dy = deltaY;
}
Player::~Player()
{

}
