#pragma once

#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include "Layout.h"

//Game class
class Game
{
//Private variables
private:
	sf::RenderWindow* window;
	sf::Event e;
	int width;
	int height;
	sf::Sprite backgroud, platform, player;
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
	sf::Vector2u getSize();
	void setSprites(Layout * const l);
	~Game();
};

