#include "Menu.h"
#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include <string>

//Add functions for setColor, setSize, setPosition, setStyle

Menu::Menu()
{
	if (!font.loadFromFile("fonts/font1.ttf"))
	{
		std::cout << "Font cant be loaded";
	}
}

void Menu::setText(std::string txt)
{
	t.setFont(font);
	t.setString(txt);
	t.setCharacterSize(30);
	//REPLACE WITH FUNCTION FOR CENTER OF SCREEN
	t.setPosition(sf::Vector2f(100, 300));
	t.setFillColor(sf::Color::Red);
	t.setStyle(sf::Text::Bold | sf::Text::Underlined);
}

void Menu::show(sf::RenderWindow *window)
{
	window->draw(t);
}


Menu::~Menu()
{
}
