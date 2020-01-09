#pragma once

#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include "Layout.h"
#include "Point.h"
#include "Player.h"
#include "resource.h"
#include "Menu.h"

//Game class
class Game
{
//Private Variables
private:
	//Window info
	sf::RenderWindow* window;
	sf::Event e;

	//Player info
	Player* p;
	const int distinct = 200;
	float dy;
	int score;
	int width;
	int height;
	bool dead = true;

	//Textures and helpers
	sf::Sprite backgroud, platform, player;
	Point platformPosition[20];
	bool platformInit = false;
	int* arr = nullptr;

//Private methods
private:
	//Window info
	void initVariables();
	void initGameWindow();

	//Game functionality
	void startGame();
	void pollEvents();

	//Player interactions
	void makePlayerAlive();
	void movePlayer();
	void checkIfPlayerIsDead();

	//Platforms
	void drawplatformPosition();
	void createPlatformPosition();

	//Menu
	void displayMainMenu(Menu title, Menu info, Menu scoreText);

	//Helpers
	bool inRange(int start, int end, int nbr);
	sf::Vector2f centerOfScreen();
	bool checkIfNumberExist(Point* arr, int n, int y);
	sf::Vector2u getSize() const;

//Public methods
public:
	//Constructor
	Game(int width, int height);

	//Game functionality
	void update();
	void render();

	//Textures
	void setBackgound(const Layout* l);
	void setPlatform(const Layout* l);
	void setPlayer(const Layout* l);

	//Helpers
	sf::RenderWindow* getWindow();
	bool isRunning();

	//Destructor
	~Game();


};

