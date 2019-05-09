#pragma once
#include "Shape.hpp"

class Square : public Shape
{
private:
	sf::RectangleShape square;
protected:
	void setPosition(float x, float y) override;
	void setColor(unsigned R, unsigned G, unsigned B) override;
public:
	Square();
	~Square() override;

	void change() override;
	void draw(sf::RenderWindow const& window) override;
};