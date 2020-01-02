#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include "Game.h"
#include "Layout.h"
#include "Player.h"

using namespace sf;
int main()
{
	//Create game window
	Game game(400,560);

	//Create layout for game
	Layout *l=new Layout();
	l->setSprites("images/background.png", "images/platform.png", "images/doodle.png");
	game.setSprites(l);

	//Game loop
	while (game.isRunning())
	{		
		game.update();
		game.render();
	}

	return 0;
 }