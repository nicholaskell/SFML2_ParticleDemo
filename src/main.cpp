/*
 * main.cpp
 *
 *  Created on: Apr 26, 2012
 *      Author: nick
 */

#include <SFML/Graphics.hpp>

#include "emitter/Emitter.h"

int main() {
	srand((unsigned) time(0));
	// Create the main window
	sf::RenderWindow window(sf::VideoMode(1200, 600), "SFML window");

	// Load a sprite to display
	sf::Texture texture;
	if (!texture.loadFromFile("media/particle.png"))
		return EXIT_FAILURE;
//     sf::Sprite sprite(texture);

	ic::Emitter emitter;
	emitter.setRenderWindow(&window);
//     emitter.start();
	window.setFramerateLimit(30);

	emitter.setNumberOfParticles(500);
	// Start the game loop
	while (window.isOpen()) {
		// Process events
		sf::Event event;
		while (window.pollEvent(event)) {
			// Close window : exit
			if (event.type == sf::Event::Closed)
				window.close();
		}
		emitter.update();

		// Clear screen
		window.clear();
		emitter.draw();
		// Draw the sprite
//         window.draw(sprite);

// Update the window
		window.display();

	}

	return EXIT_SUCCESS;
}
