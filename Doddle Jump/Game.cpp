#include "Game.h"


using namespace sf;

//Create window with given width / height.
Game::Game(int width, int height)
{
	this->width = width;
	this->height = height;
	initVariables();
	initGameWindow();
}

//Initialize variables, create Player
void Game::initVariables()
{
	//Set window pointer on NULL (dont needed, just for safe)
	//NEEDS TO BE DELETED
	this->window = nullptr;
	p = new Player(this->platformPosition);
	p->setInfo(width, height, distinct, dy);
}

//Creating game window
void Game::initGameWindow()
{
	this->window=new sf::RenderWindow(VideoMode(this->width, this->height), "Doodle Jump!");
	window->setFramerateLimit(60);
}

void Game::startGame()
{
	if (Keyboard::isKeyPressed(Keyboard::Space))
	{
		std::cout << "First" << dead << "\n";
		this->dead = false;
		std::cout << dead << "\n";
	}
}


//Functionality
void Game::update()
{
	//Every time check if there is pollEvents

	checkIfPlayerIsDead();
	pollEvents();
	p->playerActions();
}

void Game::makePlayerAlive()
{
	this->dead = false;
	p->playerPosition.x = 0;
	p->playerPosition.y = 0;
	platformInit = false;
	dy = 0;
}

//Render game window
void Game::render()
{
	//Draw background
	this->window->draw(this->backgroud);

	//Create Menu objects (with custom fonts), for showing text
	Menu title("fonts/font1.ttf");
	Menu info("fonts/font1.ttf");
	Menu scoreText("fonts/font1.ttf");

	if (this->dead)
	{
		//
		displayMainMenu(title,info,scoreText);
	}
	//Add score text
	/*
	--
	*/
	else
	{
		player.setPosition(p->playerPosition.x, p->playerPosition.y);
		this->window->draw(this->player);
		drawplatformPosition();
	}


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
		case sf::Event::MouseButtonPressed:
			makePlayerAlive();
			break;
		}
	}
}

void Game::movePlayer()
{
	if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		
		if ((p->playerPosition.x += 3) + 50 <= this->width)
			p->playerPosition.x += 3;
		else
			p->playerPosition.x = -20;
	}
	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		if ((p->playerPosition.x -= 3) > 0)
			p->playerPosition.x -= 3;
		else
			p->playerPosition.x = this->width;
	}
	player.setPosition(p->playerPosition.x, p->playerPosition.y);
}

void Game::checkIfPlayerIsDead()
{
	if (p->playerPosition.y > (height)-120)
	{
		this->dead = true;
	}
}

sf::RenderWindow* Game::getWindow()
{
	return window;
}

void Game::setBackgound(const Layout* l)
{
	this->backgroud = l->getSprite();
}

void Game::drawPlatforms()
{
	createPlatformPosition();
	for (int i = 0; i < 10; i++)
	{
		platform.setPosition(platformPosition[i].x, platformPosition[i].y);
		this->window->draw(platform);
	}
}
void Game::drawplatformPosition()
{
	//Need to add margin between every object
	if (!this->platformInit)
	{
		//PLATFORMS POSITION NEEDS TO SET ONLY ONCE, AT BEGINNING OF GAME
		this->createPlatformPosition();
	}
	for (int i = 0; i < 10; i++)
	{
		platform.setPosition(platformPosition[i].x, platformPosition[i].y);
		window->draw(platform);
	}

}

void Game::setPlatform(const Layout* l)
{
	this->platform = l->getSprite();
}

void Game::setPlayer(const Layout* l)
{
	this->player = l->getSprite();
}

//NEED TO REPLACE TEXT WITH TEXT FROM RESOURCES.h FILE
void Game::displayMainMenu(Menu title,Menu info,Menu scoreText)
{
	sf::Vector2f center = this->centerOfScreen();
	center.x = 50;
	center.y -= 100;


	//Name of game
	title.setText("Doddle Jump");
	title.setColor(sf::Color::Black);
	title.setPosition(center);
	title.setSize(40);
	title.show(window);

	//Info
	center.y += 100;
	center.x += 20;
	info.setText("Space to Start game");
	info.setColor(sf::Color::Black);
	info.setPosition(center);
	info.setSize(20);
	info.show(window);
}

void Game::createPlatformPosition()
{
	for (int i = 0; i < 10; i++)
	{
		//First- create random number (height of platform)
		int y = rand() % this->height;
		//Second- check if another platform is to close
		if (!checkIfNumberExist(platformPosition, (sizeof(platformPosition) / sizeof(*platformPosition)), y))
			//Look another number
		{
			while (1)
			{
				y = rand() % this->height;
				if (checkIfNumberExist(platformPosition, (sizeof(platformPosition) / sizeof(*platformPosition)), y))
					break;
			}
		}
		platformPosition[i].y = y;
		platformPosition[i].x = rand() % this->width;
	}
	this->platformInit = true;
}

bool Game::inRange(int start, int end, int nbr)
{
	//Returns true if nubmer IS in range
	for (int i = start; i < end; i++)
	{
		if (i == nbr)
			return true;
	}
	return false;
}

sf::Vector2f Game::centerOfScreen()
{
	return Vector2f(width / 2, height / 2);
}

bool Game::checkIfNumberExist(Point* arr, int n, int y)
{
	//Returns true if 
	for (int i = 0; i < n; i++)
	{
		if (inRange((arr + i)->y, (arr + i)->y + 25, y))
			return false;
	}
	return true;
}

sf::Vector2u Game::getSize() const
{
	return window->getSize();
}

//Return true if game is stil running
bool Game::isRunning()
{
	return window->isOpen();
}

Game::~Game()
{
	//Delete window pointer
	delete this->window;
}
