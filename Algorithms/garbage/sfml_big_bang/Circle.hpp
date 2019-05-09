#pragma once
#include "Shape.hpp"

class Circle : public Shape
{
private:
	sf::CircleShape circle;
protected:
	void setPosition(float x, float y) override;
	void setColor(unsigned R, unsigned G, unsigned B) override;
public:
	Circle();
	~Circle() override;

	void change() override;
	void draw(sf::RenderWindow const& window) override;
};
