// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "Circle.hpp"

void Circle::setPosition(float x, float y)
{
	this->circle.setPosition(sf::Vector2f(x, y));
};
void Circle::setColor(unsigned R, unsigned G, unsigned B)
{
	this->circle.setFillColor(sf::Color(R, G, B));
};

Circle::Circle(void)
{
	this->circle.setRadius(rangeSize(mt19937_random));
	this->angle = rangeAngle(mt19937_random);
	this->speed = rangeSpeed(mt19937_random);
	this->setPosition
	(
		static_cast<float>(1280.f / 2.f), 
		static_cast<float>(720.f / 2.f)
	);
	this->setColor(rangeColor(mt19937_random), rangeColor(mt19937_random), rangeColor(mt19937_random));
};

void Circle::change(void)
{
	this->setPosition
	(
		static_cast<float>(this->circle.getPosition().x + this->speed * sin(this->angle * M_PI / 180)),
		static_cast<float>(this->circle.getPosition().y + this->speed * cos(this->angle * M_PI / 180))
	);
};
void Circle::changeColor(void)
{
	this->setColor(rangeColor(mt19937_random), rangeColor(mt19937_random), rangeColor(mt19937_random));
};
void Circle::draw(sf::RenderWindow const& window)
{
	const_cast<sf::RenderWindow&>(window).draw(circle);
};