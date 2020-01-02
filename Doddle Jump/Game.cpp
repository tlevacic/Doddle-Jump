#include "Game.h"
#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include "Point.h"

using namespace sf;


void Game::initVariables()
{
	//Set window pointer on NULL (dont needed, just for safe)
	//NEED TO BE DELETED
	this->window = nullptr;
	this->playerPosition.x = 100;
	this->playerPosition.y = 200;
}

//Creating game window
void Game::initGameWindow()
{
	this->window=new sf::RenderWindow(VideoMode(this->width, this->height), "Doodle Jump!");
	window->setFramerateLimit(60);
}

//Create window with given width / height.
Game::Game(int width, int height)
{
	this->width = width;
	this->height = height;
	initVariables();
	initGameWindow();
}

//Return true if game is stil running
bool Game::isRunning()
{
	return window->isOpen();
}

//Functionality
void Game::update()
{
	//Every time check if there is pollEvents
	this->pollEvents();
	this->playerActions();

}

//Render game window
void Game::render()
{
	this->window->draw(this->backgroud);
	this->window->draw(this->player);
	this->drawplatformPosition();
	window->display();
}

void Game::pollEvents()
{
	while (this->window->pollEvent(this->e))
	{
		switch (this->e.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		}
	}
}

sf::Vector2u Game::getSize() const
{
	return window->getSize();
}

void Game::setSprites(Layout * const l)
{
	this->backgroud = l->getBackground();
	this->platform = l->getPlatform();
	this->player = l->getPlayer();
}



void Game::movePlayer()
{
	if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		
		if ((playerPosition.x += 3) + 50 <= this->width)
			playerPosition.x += 3;
		else
			playerPosition.x = -20;
	}
	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		if ((playerPosition.x -= 3) > 0)
			playerPosition.x -= 3;
		else
			playerPosition.x = this->width;
	}

	//NEED TO DELETE, Just for debuging
	if (Keyboard::isKeyPressed(Keyboard::Space))
	{
		playerPosition.y -= 2;
	}
	//Every time, user mofify coordinates, set new player position

	player.setPosition(playerPosition.x, playerPosition.y);
}

void Game::createPlatformPosition()
{
	for (int i = 0; i < 10; i++)
	{
		platformPosition[i].x = rand() % this->width;
		platformPosition[i].y = rand() % this->height;
	}
	this->platformInit = true;
}

void Game::drawplatformPosition()
{
	//Need to add margin between every object
	if (!this->platformInit)
	{
		this->createPlatformPosition();
	}
	for (int i = 0; i < 10; i++)
	{
		platform.setPosition(platformPosition[i].x, platformPosition[i].y);
		window->draw(platform);
	}
	
}

void Game::playerActions()
{
	movePlayer();
	playerJump();
	movePlayerScreen();
	playerCollision();
	playerDead();
}

void Game::playerDead()
{

	if (playerPosition.y > (this->height) -100)
	{
		////
		//window.close();
		dy -= 10;
	}
}

void Game::playerJump()
{
	dy += 0.3;
	playerPosition.y += dy;
}

void Game::movePlayerScreen()
{
	if (playerPosition.y < this->distinct)
		for (int i = 0; i < 10; i++)
		{
			playerPosition.y = distinct;
			platformPosition[i].y = platformPosition[i].y - dy;

			
			if (platformPosition[i].y > this->height)
			{
				platformPosition[i].y = 0;
				platformPosition[i].x = rand() % this->width;
			}
		}
}

void Game::playerCollision()
{
	for (int i = 0; i < 10; i++)
		if ((playerPosition.x + 50 > platformPosition[i].x) && 
			(playerPosition.x + 20 < platformPosition[i].x + 68)
			&& (playerPosition.y + 70 > platformPosition[i].y) 
			&& (playerPosition.y + 70 < platformPosition[i].y + 14)
			&& (dy > 0))
			dy = -10;

}


Game::~Game()
{
	//Delete window pointer
	delete this->window;
}
