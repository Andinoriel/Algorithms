#pragma once
#ifndef __SHAPE_HPP__
#define __SHAPE_HPP__

#include <SFML/Graphics.hpp>

#define _USE_MATH_DEFINES
#include <math.h>

#include "RandomF.hpp"

class Shape
{
protected:
	float angle, speed;

	virtual void setPosition(float x, float y) = 0;
	virtual void setColor(unsigned R, unsigned G, unsigned B) = 0;
public:
	Shape(void) = default;
	virtual ~Shape(void) {};

	virtual void change(void) = 0;
	virtual void changeColor() = 0;
	virtual void draw(sf::RenderWindow const& window) = 0;
};

#endif // !__SHAPE_HPP__