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
	this->movePlayer();
	//Hero needs to be added game logic!!!!
	//
	//
	//
	//
	//
	//_------------------------------------
}

//Render game window
void Game::render()
{
	//window->draw();
	this->window->draw(this->backgroud);
	//Hero needs to be added drawing platorms!!!!
	//
	//
	//
	//
	//
	//_------------------------------------
	this->window->draw(this->player);
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

void Game::createPlatforms()
{
	//Need to add margin between every object
	for (int i = 0; i < 10; i++)
	{
		platforms[i].x = rand() % this->width;
		platforms[i].y = rand() % this->height;
	}
}

void Game::movePlayer()
{
	if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		
		if ((playerPosition.x += 1) + 50 <= this->width)
			playerPosition.x += 1;
		else
			playerPosition.x = -20;
	}
	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		if ((playerPosition.x -= 1) > 0)
			playerPosition.x -= 1;
		else
			playerPosition.x = this->width;
	}
	//Every time, user mofify coordinates, set new player position
	player.setPosition(playerPosition.x, playerPosition.y);

	std::cout << "Coordinates are " << playerPosition.x << " " << playerPosition.y<<"\n";
}


Game::~Game()
{
	//Delete window pointer
	delete this->window;
}
