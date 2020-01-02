#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include "Game.h"
#include "Layout.h"

using namespace sf;
int main()
{
	Game game(400,500);
	Event e;
	Layout *l=new Layout();
	l->setSprites("images/sky.png", "images/platform.png", "images/doodle.png");
	game.setSprites(l);

	while (game.isRunning())
	{		
		game.update();
		game.render();
	}
 }