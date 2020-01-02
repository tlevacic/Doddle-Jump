#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include "Game.h"
#include "Layout.h"

using namespace sf;
int main()
{
	//Add game class
	//Add menu class
	Game game(400,500);
	Event e;
	Layout l(&game);
	while (game.isRunning())
	{		
		game.update();
		game.render();
	}
 }