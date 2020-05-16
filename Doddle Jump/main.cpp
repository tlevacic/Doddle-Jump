#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include "Game.h"
#include "Layout.h"
#include "Player.h"
#include "Menu.h"

using namespace sf;
int main()
{
	//Create game window
	Game game(400,560);

	//Create layouts for game
	Layout gameBackground(game.getWindow());
	Layout platform(game.getWindow());
	Layout doodle(game.getWindow());

	//Create layouts textures
	gameBackground.createGameBackground("images/background.png");
	platform.createSprite("images/platform.png");
	doodle.createSprite("images/doodle.png");

	//Connect layouts objects with game layouts
	game.setBackgound(&gameBackground);
	game.setPlatform(&platform);
	game.setPlayer(&doodle);


	//Game loop

	while (game.isRunning())
	{		
		game.update();
		game.render();
	}

	return 0;
 }