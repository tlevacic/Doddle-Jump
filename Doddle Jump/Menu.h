#pragma once

#include "Menu.h"
#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include <string>

//Menu class
class Menu
{
private:
	sf::Font font;
	sf::Text t;
public:
	Menu();
	void setText(std::string txt);
	void setColor(sf::Color c);
	void setSize(int s);
	void setPosition(sf::Vector2f p);
	void setStyle();
	void show(sf::RenderWindow *window);
	~Menu();
};

