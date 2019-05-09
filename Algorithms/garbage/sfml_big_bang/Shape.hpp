#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include <SFML/Graphics.hpp>
#include "RandomF.hpp"


class Shape
{
protected:
	float angle, speed;

	virtual void setPosition(float x, float y) = 0;
	virtual void setColor(unsigned R, unsigned G, unsigned B) = 0;
public:
	Shape() {};
	virtual ~Shape() = 0;

	virtual void change() = 0;
	virtual void draw(sf::RenderWindow const& window) = 0;
};