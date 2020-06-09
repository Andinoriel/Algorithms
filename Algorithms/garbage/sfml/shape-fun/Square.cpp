// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "Square.hpp"

void Square::setPosition(float x, float y)
{
	this->square.setPosition(sf::Vector2f(x, y));
};
void Square::setColor(unsigned R, unsigned G, unsigned B)
{
	this->square.setFillColor(sf::Color(R, G, B));
};

Square::Square(void)
{
	float tmp = rangeSize(mt19937_random);
	this->square.setSize(sf::Vector2f(tmp, tmp));
	this->angle = rangeAngle(mt19937_random);
	this->speed = rangeSpeed(mt19937_random);
	this->setPosition
	(
		static_cast<float>(1280.f / 2.f), 
		static_cast<float>(720.f / 2.f)
	);
	this->setColor(rangeColor(mt19937_random), rangeColor(mt19937_random), rangeColor(mt19937_random));
};

void Square::change(void)
{
	this->setPosition
	(
		static_cast<float>(this->square.getPosition().x + this->speed * sin(this->angle * M_PI / 180)),
		static_cast<float>(this->square.getPosition().y + this->speed * cos(this->angle * M_PI / 180))
	);
};
void Square::changeColor(void)
{
	this->setColor(rangeColor(mt19937_random), rangeColor(mt19937_random), rangeColor(mt19937_random));
};
void Square::draw(sf::RenderWindow const& window)
{
	const_cast<sf::RenderWindow&>(window).draw(square);
};