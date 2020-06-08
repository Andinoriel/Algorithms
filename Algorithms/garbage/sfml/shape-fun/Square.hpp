#pragma once
#ifndef __SQUARE_HPP__
#define __SQUARE_HPP__

#include "Shape.hpp"

class Square : public Shape
{
private:
	sf::RectangleShape square;
protected:
	void setPosition(float x, float y) override;
	void setColor(unsigned R, unsigned G, unsigned B) override;
public:
	Square(void);
	~Square(void) override = default;

	void change(void) override;
	void changeColor(void) override;
	void draw(sf::RenderWindow const& window) override;
};

#endif // !__SQUARE_HPP__