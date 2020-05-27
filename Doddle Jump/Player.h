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

