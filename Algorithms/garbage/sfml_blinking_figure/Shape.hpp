#pragma once
#include <SFML/Graphics.hpp>
#include "RandomF.hpp"

class Shape
{
protected:
	virtual void setPosition(float, float) = 0;
	virtual void setSize(float) = 0;
	virtual void setColor(unsigned, unsigned, unsigned) = 0;
public:
	Shape() {};
	virtual ~Shape() = 0;

	virtual void change() = 0;
	virtual void changeColor() = 0;
	virtual void draw(sf::RenderWindow const&) = 0;
};