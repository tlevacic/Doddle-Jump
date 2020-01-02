#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include "Game.h"

using namespace sf;
int main()
{
	//Add game class
	//Add menu class
	Game game(400,500);
	Event e;

	while (game.isRunning())
	{		
		game.update();
		game.render();
	}
 }