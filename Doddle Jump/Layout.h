#pragma once


#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include <string>


class Layout
{
private:
	sf::Vector2u TextureSize;  //Added to store texture size.
	sf::Vector2u WindowSize;   //Added to store window size.
	sf::Texture backG, plat, play;
	sf::Sprite background, platform, player;

public:
	Layout();
	int setSprites(std::string s1, std::string s2, std::string s3);
	sf::Sprite getBackground();
	sf::Sprite getPlatform();
	sf::Sprite getPlayer();
	~Layout();
};

