// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "Circle.hpp"

void Circle::setPosition(float x, float y)
{
	this->circle.setPosition(sf::Vector2f(x, y));
}
void Circle::setColor(unsigned R, unsigned G, unsigned B)
{
	this->circle.setFillColor(sf::Color(R, G, B));
}

Circle::Circle()
{
	this->circle.setRadius(rangeSize(random));
	this->angle = rangeAngle(random);
	this->speed = rangeSpeed(random);
	this->setPosition
	(
		static_cast<float>(GetSystemMetrics(SM_CXSCREEN) / 2), 
		static_cast<float>(GetSystemMetrics(SM_CYSCREEN) / 2)
	);
	this->setColor(rangeColor(random), rangeColor(random), rangeColor(random));
}
Circle::~Circle()
{
	;
}

void Circle::change()
{
	this->setPosition
	(
		static_cast<float>(this->circle.getPosition().x + this->speed * sin(this->angle * M_PI / 180)),
		static_cast<float>(this->circle.getPosition().y + this->speed * cos(this->angle * M_PI / 180))
	);
}
void Circle::draw(sf::RenderWindow const& window)
{
	const_cast<sf::RenderWindow&>(window).draw(circle);
}