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

public:
	sf::RenderWindow* window;
	Player *p;
	sf::Event e;
	const int distinct=200;
	float dy = 0;
	sf::Sprite backgroud, platform, player;
public :
	Point platformPosition[20];
	int *arr = nullptr;
	void startGame();
	bool platformInit = false;
	int score = 0;
	int width;
	int height;
	void initVariables();
	void initGameWindow();
	Game(int width,int height);
	bool isRunning();
	void update();
	void makePlayerAlive();
	void render();
	void pollEvents();
	bool checkIfNumberExist(Point* arr, int n, int y);
	sf::Vector2u getSize() const;
	void movePlayer();
	bool dead = true;
	void checkIfPlayerIsDead();
	sf::RenderWindow *getWindow();
	void setBackgound(const Layout* l);
	void drawPlatforms();
	void drawplatformPosition();
	void setPlatform(const Layout* l);
	void setPlayer(const Layout* l);
	void displayMainMenu(Menu title, Menu info, Menu scoreText);
	void createPlatformPosition();
	~Game();

//Help methods
private:
	bool inRange(int start, int end, int nbr);
	sf::Vector2f centerOfScreen();


};

