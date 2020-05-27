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
		
		this->dead = false;
		
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
	score = 0;
	p->score = 0;
	this->dead = false;
	Vector2f center = centerOfScreen();
	p->playerPosition.x = platformPosition[0].x;
	p->playerPosition.y = platformPosition[0].y - cPlatformWidth;
	platformInit = false;
	dy = 0;
	p->dy = 0;
}

//Render game window
void Game::render()
{
	//Draw background
	this->window->draw(this->backgroud);

	Menu title("fonts/font1.ttf");
	Menu info("fonts/font1.ttf");
	Menu scoreText("fonts/font1.ttf");

	if (this->dead)
		displayMainMenu(title,info,scoreText);
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


void Game::checkIfPlayerIsDead()
{
	if (p->playerPosition.y + cPlatformWidth > height)
	{
		this->dead = true;
		score = p->getPlayerScore();
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


void Game::drawplatformPosition()
{
	if (!this->platformInit)
	{
		this->createPlatformPosition2();
	}
	for (int i = 0; i < cNumberOfPlatforms; i++)
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

void Game::displayMainMenu(Menu title,Menu info,Menu scoreText)
{
	sf::Vector2f center = this->centerOfScreen();
	center.x = 50;
	center.y -= 100;


	//Name of game
	title.setText("Doddle Jump");
	title.setColor(sf::Color::Black);
	title.setPosition(center);
	title.setSize(cSizeOfText40);
	title.show(window);

	//Info
	center.y += cMoveTextY;
	center.x += cMoveTextX;
	info.setText("Left Click to Start game");
	info.setColor(sf::Color::Black);
	info.setPosition(center);
	info.setSize(cSizeOfText20);
	info.show(window);
	if (score != 0)
	{
		sf::Vector2f center2 = this->centerOfScreen();
		center2.y = center.y + cMoveScoreTextY;
		center2.x -= cMoveScoreTextX;
		scoreText.setText("Score: " + std::to_string(score));
		scoreText.setColor(sf::Color::Black);
		scoreText.setPosition(center2);
		scoreText.setSize(15);
		scoreText.show(window);
	}
}

void Game::createPlatformPosition2()
{
	int min = 0;
	int validHeight = height / cNumberOfPlatforms - cPlatformHeight;
	int max = validHeight; //Height of platform
	int range = max - min + 1;
	int num = rand() % range + min;
	Vector2f center = centerOfScreen();
	platformPosition[0].x = center.y- cPlatformWidth; //Minus width of platform
	platformPosition[0].y = height- cPlatformHeight;
	for (int i = 1; i < cNumberOfPlatforms; i++)
	{
		platformPosition[i].y = num;
		num += cDistancePlatforms;
		platformPosition[i].x = rand() % (width - cPlayerWidth);
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
bool Game::isRunning()
{
	return window->isOpen();
}
Game::~Game()
{
	delete this->window;
	delete this->p;
}
