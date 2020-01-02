#pragma once

#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include "Layout.h"
#include "Point.h"
#include "Player.h"

//Game class
class Game
{
//Private variables
	////

	public:
	Player *p;
	sf::RenderWindow* window;
	sf::Event e;
	const int distinct=200;
	float dy = 0;
	sf::Sprite backgroud, platform, player;
	Point platformPosition[20];
	bool platformInit = false;

//Public variables
public:
	int width;
	int height;

//Private methods
	void initVariables();
	void initGameWindow();
private:


//Public methods
public:
	Game(int width,int height);
	bool isRunning();
	void update();
	void render();
	void pollEvents();
	sf::Vector2u getSize() const;
	void setSprites(Layout * const l);
	void movePlayer();
	void createPlatformPosition();
	void drawplatformPosition();

	~Game();

//Help methods
private:
	bool checkIfNumberExist(Point *arr,int n,int y);
	bool inRange(int start,int end, int nbr);
};

