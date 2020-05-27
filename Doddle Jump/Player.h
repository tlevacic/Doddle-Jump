#pragma once

#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include "Point.h"

class Player
{
//Private variables
private:
	int width;
	int height;
	int distinct;
	Point* platformPosition;
	float cDy = 0.3;
	int cNumberOfPlatforms = 10;
	int cPlayerWidth = 50;
	int cPlatformWidth = 70;
	int cMovePlayer = 5;
	int cLeftSizeOfScreen = 20;
	int cAddScoreValue = 1;
	int cBottomPlatformDistance = 13;
	int cAddHeightToPlayer = 50;
	int cPlatformHeight = 14;

public: int score;
public: float dy;
	

//Public variables
public:
	Point playerPosition;

//Private methods
private:
	void playerJump();
	void movePlayerScreen();
	void playerCollision();
	void movePlayer();

//Public methods
public:
	void playerActions();
	int getPlayerScore();
	void setInfo(int width, int height, int distinct, int deltaY);

	//Constuctor & Destructor
	Player(Point* p);
};

