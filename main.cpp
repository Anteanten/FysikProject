#include <SFML/Graphics.hpp>
#include "Rocket.h"
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
	sf::View view = window.getView();

	sf::Clock clock;
	float deltaTime;

	Rocket rocket(sf::Vector2f(400, 550), sf::Vector2f(0, 0), 10000, sf::Vector2f(0, -1));

	while (window.isOpen())
	{
		window.clear();
		
		//INPUT

		sf::Event event;
		while (window.pollEvent(event))
		{
			switch(event.type) {
				//Window X Button, cloase window
				case sf::Event::Closed:
					window.close();
					break;
				//MouseScroll, Zoom window
				case sf::Event::MouseWheelScrolled:
					if (event.mouseWheel.x > 0) {
						view.setSize(view.getSize() * (float)1.01);
					}
					else {
						view.setSize(view.getSize() * (float)0.99);
					};
					window.setView(view);
					break;
				//WASD, Move camera
				case sf::Event::KeyPressed:
					if (event.key.code == sf::Keyboard::W) {
						view.setCenter(view.getCenter() + sf::Vector2f(0, -5));
					}
					else if (event.key.code == sf::Keyboard::S) {
						view.setCenter(view.getCenter() + sf::Vector2f(0, 5));
					}
					else if (event.key.code == sf::Keyboard::A) {
						view.setCenter(view.getCenter() + sf::Vector2f(-5, 0));
					}
					else if (event.key.code == sf::Keyboard::D) {
						view.setCenter(view.getCenter() + sf::Vector2f(5, 0));
					}
					window.setView(view);
					break;
			}
		}

		//Main Loop
		deltaTime = clock.restart().asSeconds();

		//Update
		rocket.update(deltaTime, 9.82);

		//Render
		rocket.draw(window);

		window.display();
	}

	return 0;
}