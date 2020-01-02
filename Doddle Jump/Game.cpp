#include "Game.h"
#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>

using namespace sf;


void Game::initVariables()
{
	//Set window pointer on NULL (dont needed, just for safe)
	//NEED TO BE DELETED
	this->window = nullptr;
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


Game::~Game()
{
	//Delete window pointer
	delete this->window;
}
