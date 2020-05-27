#include "Layout.h"
#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>



Layout::Layout(sf::RenderWindow* window)
{
	WindowSize = window->getSize(); //Get size of window.
}

int Layout::createGameBackground(std::string s)
{
	if (!texture.loadFromFile(s))
	{
		return -1;
	}
	else
	{
		//Set valid width and height for background
		this->TextureSize = texture.getSize();			//Get size of texture.
            

		float ScaleX = (float)WindowSize.x / TextureSize.x;
		float ScaleY = (float)WindowSize.y / TextureSize.y;     //Calculate scale.

		this->sprite.setTexture(texture);
		this->sprite.setScale(ScaleX, ScaleY);      //Set scale.  
		return 1;
	}
}

int Layout::createSprite(std::string s)
{
	if (this->texture.loadFromFile(s))
	{
		this->sprite.setTexture(this->texture);
		return 1;
	}
	return -1;
}

sf::Sprite Layout::getSprite() const
{
	return this->sprite;
}

