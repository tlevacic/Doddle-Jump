#include "Layout.h"
#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include "Game.h"


Layout::Layout(Game* g)
{
	this->WindowSize = g->getSize(); //Get size of window.
}

int Layout::setSprites(std::string s1, std::string s2, std::string s3)
{
	//First, need to load png from files into textures
	//Second, need to setTexture to sprite
	if (!backG.loadFromFile(s1))
	{
		return -1;
	}
	else
	{
		//Set valid width and height for background
		this->TextureSize = backG.getSize();			//Get size of texture.
            

		float ScaleX = (float)WindowSize.x / TextureSize.x;
		float ScaleY = (float)WindowSize.y / TextureSize.y;     //Calculate scale.

		this->background.setTexture(backG);
		this->background.setScale(ScaleX, ScaleY);      //Set scale.  
	}

	if(this->plat.loadFromFile(s2))
		this->platform.setTexture(this->plat);
	if (this->play.loadFromFile(s3))
		this->player.setTexture(this->play);
}


Layout::~Layout()
{
}
