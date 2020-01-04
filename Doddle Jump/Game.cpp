#include "Game.h"


using namespace sf;



void Game::startGame()
{
	//
	if (Keyboard::isKeyPressed(Keyboard::Space))
	{
		this->dead = false;
	}
}

void Game::initVariables()
{
	//Set window pointer on NULL (dont needed, just for safe)
	//NEEDS TO BE DELETED
	this->window = nullptr;
	p = new Player(this->platformPosition);
	p->playerPosition.x = 0;
	p->playerPosition.y = 0;
	p->width = this->width;
	p->height = this->height;
	p->distinct = this->distinct;
	p->dy = this->dy;

	for (int i = 0;i < 10;i++)
	{
		platformPosition[i].x = 0;
		platformPosition[i].y = 0;
	}
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
	this->startGame();
	this->pollEvents();
	p->playerActions();
	this->movePlatform();

}

//Render game window
void Game::render()
{
	this->window->draw(this->backgroud);

	if (this->dead)
	{
		Menu m;
		m.setText("Doddle Jump");
		
		m.show(window);
	}
	else
	{
		player.setPosition(p->playerPosition.x, p->playerPosition.y);
		this->window->draw(this->player);
		this->drawplatformPosition();
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

	//NEED TO DELETE, Just for debuging
	/*if (Keyboard::isKeyPressed(Keyboard::Space))
	{
		playerPosition.y += 7;
	}*/
	//Every time, user mofify coordinates, set new player position

	player.setPosition(p->playerPosition.x, p->playerPosition.y);
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

void Game::movePlatform()
{
	
	//Make game harded, constantly moving platforms
	for (int i = 0;i < 10;i++)
	{
		
		//Move only specific platforms by x asis.
		/*if (*(arr + i) == i)
		{
			if (platformPosition[i].x += 3 + 68 <= this->width)
				platformPosition[i].x += 3;
		}*/
		//Move ALL platforms by Y asis.
		//platformPosition[i].y += 2;
	}
}





Game::~Game()
{
	//Delete window pointer
	delete this->window;
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

		std::cout<<"Pozicija je "<<y<<"\n";
		platformPosition[i].y = y;		
		platformPosition[i].x = rand() % this->width;
	}
	this->platformInit = true;
}

bool Game::inRange(int start, int end, int nbr)
{
	//Returns true if nubmer IS in range
	for (int i = start;i < end;i++)
	{
		if (i == nbr)
			return true;
	}
	return false;
}


bool Game::checkIfNumberExist(Point *arr, int n, int y)
{
	//Returns true if 
	for (int i = 0;i < n;i++)
	{
		if (inRange((arr+i)->y,(arr + i)->y + 25, y))
			return false;
	}
	return true;
}
