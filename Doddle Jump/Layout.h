#pragma once


#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include <string>


class Layout
{
private:
	sf::Vector2u TextureSize;  
	sf::Vector2u WindowSize;  
	sf::Texture texture;
	sf::Sprite sprite;

public:
	Layout(sf::RenderWindow *window);
	int createGameBackground(std::string s);
	int createSprite(std::string s);
	sf::Sprite getSprite() const;
	~Layout();
};
