#pragma once

#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include "Layout.h"
#include "Point.h"
#include "Player.h"
#include "strings.h"
#include "Menu.h"

#define NumOfplatformPosition 10

//Game class
class Game
{
//Private Variables
private:
	//Window info
	sf::RenderWindow* window;
	sf::Event e;

	const int cPlatformWidth = 70;
	const int cPlayerWidth = 50;
	const int cPlayerMove = 3;
	const int cPlatformHeight = 14;
	const int cLeftSizeOfScreen = 20;
	const int cNumberOfPlatforms = 10;
	const int cDistancePlatforms = 80;
	const int cMoveTextY = 100;
	const int cMoveTextX = 20;
	const int cSizeOfText20 = 20;
	const int cSizeOfText40 = 40;
	const int cMoveScoreTextY = 80;
	const int cMoveScoreTextX = 30;

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
	Point platformPosition[NumOfplatformPosition];
	bool platformInit = false;

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
	void checkIfPlayerIsDead();

	//Platforms
	void drawplatformPosition();
	void createPlatformPosition2();

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

