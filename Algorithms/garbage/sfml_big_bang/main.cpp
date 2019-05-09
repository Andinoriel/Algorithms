#include <SFML/Graphics.hpp>

#include "Circle.hpp"
#include "Square.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN)), "LW7_2", sf::Style::Fullscreen);
	window.setMouseCursorVisible(false);
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);

	random.seed(rd());

	Shape* array[100];
	for (size_t t = 0; t < 50; ++t)
		array[t] = new Circle();
	for (size_t t = 50; t < 100; ++t)
		array[t] = new Square();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
			if (event.type == sf::Event::Closed)
				window.close();

		window.clear();
		
		for (size_t t = 0; t < 100; ++t)
		{
			array[t]->change();
			array[t]->draw(window);
		}

		window.display();
	}


	return 0;
}