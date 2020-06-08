// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "Circle.hpp"
#include "Square.hpp"

int demo2(void)
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "demo2", sf::Style::Fullscreen);
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
		};

		window.display();
	};

	return 0;
};