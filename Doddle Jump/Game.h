#pragma once

#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include "Layout.h"
#include "Point.h"

//Game class
class Game
{
//Private variables
private:
	sf::RenderWindow* window;
	sf::Event e;
	int width;
	int height;
	const int distinct=250;
	float dy = 0;
	sf::Sprite backgroud, platform, player;
	Point platforms[20];
	Point playerPosition;

//Public variables
public:


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
	void createPlatforms();
	void movePlayer();
	~Game();
};

