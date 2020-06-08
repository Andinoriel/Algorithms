#pragma once
#ifndef __CIRCLE_HPP__
#define __CIRCLE_HPP__

#include "Shape.hpp"

class Circle : public Shape
{
private:
	sf::CircleShape circle;
protected:
	void setPosition(float x, float y) override;
	void setColor(unsigned R, unsigned G, unsigned B) override;
public:
	Circle(void);
	~Circle(void) override = default;

	void change(void) override;
	void changeColor(void) override;
	void draw(sf::RenderWindow const& window) override;
};

#endif // !__CIRCLE_HPP__