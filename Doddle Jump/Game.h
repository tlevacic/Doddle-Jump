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
	bool platformInit = false;
	void startGame();
	int score = 10;
	int width;
	int height;
	void initVariables();
	void initGameWindow();
	Game(int width,int height);
	bool isRunning();
	void update();
	void render();
	void pollEvents();
	sf::Vector2u getSize() const;
	void movePlayer();
	void createPlatformPosition();
	void drawplatformPosition();
	void movePlatform();
	bool dead = false;
	void playerDead();
	sf::RenderWindow *getWindow();
	void setBackgound(const Layout* l);
	void setPlatform(const Layout* l);
	void setPlayer(const Layout* l);
	~Game();

//Help methods
private:
	bool checkIfNumberExist(Point *arr,int n,int y);
	bool inRange(int start,int end, int nbr);
	sf::Vector2f centerOfScreen();


};

