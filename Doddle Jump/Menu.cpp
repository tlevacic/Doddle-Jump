#include "Menu.h"
#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include <string>


Menu::Menu(std::string s)
{
	if (!font.loadFromFile(s))
	{
		std::cout << ERROR_FONTS;
	}
}

void Menu::setText(std::string txt)
{
	t.setFont(font);
	t.setString(txt);
}

void Menu::setColor(sf::Color c)
{
	t.setFillColor(c);
}

void Menu::setSize(int s)
{
	t.setCharacterSize(s);
}

void Menu::setPosition(sf::Vector2f p)
{
	t.setPosition(sf::Vector2f(p));
}

void Menu::setStyle()
{
	t.setStyle(sf::Text::Bold | sf::Text::Underlined);
}

void Menu::show(sf::RenderWindow *window)
{
	window->draw(t);
}

