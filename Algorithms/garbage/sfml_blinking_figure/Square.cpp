// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "Square.hpp"

void Square::setPosition(float x, float y)
{
	this->square.setPosition(sf::Vector2f(x, y));
}
void Square::setSize(float size)
{
	this->square.setSize(sf::Vector2f(size, size));
}
void Square::setColor(unsigned R, unsigned G, unsigned B)
{
	sf::Color color(R, G, B);
	this->square.setFillColor(color);
}

Square::Square()
{
	this->square.setSize(sf::Vector2f(0, 0));
}
Square::~Square()
{
	;
}

void Square::change()
{
	this->setPosition(rangeCoordX(random), rangeCoordY(random));
	this->setSize(rangeSize(random));
}
void Square::changeColor()
{
	this->setColor(rangeColor(random), rangeColor(random), rangeColor(random));
}
void Square::draw(sf::RenderWindow const& window)
{
	const_cast<sf::RenderWindow&>(window).draw(square);
}