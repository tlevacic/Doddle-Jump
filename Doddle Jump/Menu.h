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
	Menu(std::string s);
	void setText(std::string txt);
	void setColor(sf::Color c);
	void setSize(int s);
	void setPosition(sf::Vector2f p);
	void setStyle();
	void show(sf::RenderWindow *window);
	~Menu();
};

/*
For use Menu class, need to define:
1. Create object - Menu nameOfObject("pathToFontFile");
2. Add props ( nameOfObject.setText("test1") .....)
3. Show menu on custom window (nameOfObject.show(this->window));
*/


