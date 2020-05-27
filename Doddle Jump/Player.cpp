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
	dy += cDy;
	playerPosition.y += dy;
}

void Player::movePlayerScreen()
{
	int num = 0;

	if (playerPosition.y <distinct)
		for (int i = 0; i < cNumberOfPlatforms; i++)
		{
			playerPosition.y = distinct;
			platformPosition[i].y = platformPosition[i].y - dy;


			if (platformPosition[i].y > height- cBottomPlatformDistance)
			{
				platformPosition[i].y = num;
				num += cAddHeightToPlayer;
				platformPosition[i].x = rand() % (width - cPlayerWidth);
			}
		}
}


void Player::playerCollision()
{
	//Fixed values based on size of picture
	for (int i = 0; i < cNumberOfPlatforms; i++)
		if ((playerPosition.x + cPlayerWidth > platformPosition[i].x) &&
			(playerPosition.x + cLeftSizeOfScreen < platformPosition[i].x + cPlatformWidth)
			&& (playerPosition.y + cPlatformWidth > platformPosition[i].y)
			&& (playerPosition.y + cPlatformWidth < platformPosition[i].y + cPlatformHeight)
			&& (dy > 0))
		{
			dy = -10;
			score += cAddScoreValue;
		}
}

void Player::movePlayer()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{

		if ((playerPosition.x += cMovePlayer) + cPlayerWidth <= width)
			playerPosition.x += cMovePlayer;
		else
			playerPosition.x = -cLeftSizeOfScreen;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if ((playerPosition.x -= cMovePlayer) > 0)
			playerPosition.x -= cMovePlayer;
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