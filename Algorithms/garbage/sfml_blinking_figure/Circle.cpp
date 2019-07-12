// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "Circle.hpp"

void Circle::setPosition(float x, float y)
{
	this->circle.setPosition(sf::Vector2f(x, y));
}
void Circle::setSize(float r)
{
	this->circle.setRadius(r);
}
void Circle::setColor(unsigned R, unsigned G, unsigned B)
{
	sf::Color color(R, G, B);
	this->circle.setFillColor(color);
}

Circle::Circle()
{
	circle.setRadius(0);
}
Circle::~Circle()
{
	;
}

void Circle::change()
{
	this->setPosition(rangeCoordX(random), rangeCoordY(random));
	this->setSize(rangeSize(random));
}
void Circle::changeColor()
{
	this->setColor(rangeColor(random), rangeColor(random), rangeColor(random));
}
void Circle::draw(sf::RenderWindow const & window)
{
	const_cast<sf::RenderWindow&>(window).draw(circle);
}