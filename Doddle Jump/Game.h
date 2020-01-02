#pragma once

#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
//Game class
class Game
{
//Private variables
private:
	sf::RenderWindow* window;
	sf::Event e;
	int width;
	int height;
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
	~Game();
};

