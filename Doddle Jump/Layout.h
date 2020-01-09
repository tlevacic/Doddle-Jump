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
	sf::Texture texture;
	sf::Sprite sprite;

public:
	Layout(sf::RenderWindow *window);
	int createGameBackground(std::string s);
	int createSprite(std::string s);
	sf::Sprite getSprite() const;
	~Layout();
};

/*
For use Layout class, need to define:
1. Layout nameOfObject (adress of game window);
2. nameOfObject.createGameBackground("filename") || nameOfObject.createSprite("filename");
3. Connect game with layouts through game class (nameOfObject.getSprite())
*/
