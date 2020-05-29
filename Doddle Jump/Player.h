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
	std::vector<Point>& platformPosition;
	const float cDy = 0.3f;
	const int cPlayerWidth = 50;
	const int cPlatformWidth = 70;
	const int cMovePlayer = 5;
	const int cLeftSizeOfScreen = 20;
	const int cAddScoreValue = 1;
	const int cBottomPlatformDistance = 13;
	const int cAddHeightToPlayer = 50;
	const int cPlatformHeight = 14;

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
	Player(std::vector<Point>&);
};