#include "Square.hpp"

void Square::setPosition(float x, float y)
{
	this->square.setPosition(sf::Vector2f(x, y));
}
void Square::setColor(unsigned R, unsigned G, unsigned B)
{
	this->square.setFillColor(sf::Color(R, G, B));
}

Square::Square()
{
	float tmp = rangeSize(random);
	this->square.setSize(sf::Vector2f(tmp, tmp));
	this->angle = rangeAngle(random);
	this->speed = rangeSpeed(random);
	this->setPosition
	(
		static_cast<float>(GetSystemMetrics(SM_CXSCREEN) / 2),
		static_cast<float>(GetSystemMetrics(SM_CYSCREEN) / 2)
	);
	this->setColor(rangeColor(random), rangeColor(random), rangeColor(random));
}
Square::~Square()
{
	;
}

void Square::change()
{
	this->setPosition
	(
		static_cast<float>(this->square.getPosition().x + this->speed * sin(this->angle * M_PI / 180)),
		static_cast<float>(this->square.getPosition().y + this->speed * cos(this->angle * M_PI / 180))
	);
}
void Square::draw(sf::RenderWindow const& window)
{
	const_cast<sf::RenderWindow&>(window).draw(square);
}