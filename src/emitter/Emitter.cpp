/*
 * Emitter.cpp
 *
 *  Created on: Apr 26, 2012
 *      Author: nick
 */

#include "Emitter.h"

namespace ic {

	Emitter::Emitter() {
		// TODO Auto-generated constructor stub
		texture.loadFromFile("media/particle.png");
//		particle.setTexture(texture);
		frequencyOfRelease = sf::milliseconds(70);
//		particle.setPosition(100, 100);
		for (int i = 0; i < NUM_PARTICLES; i++) {
//			texture.loadFromFile("media/particle.png");
			particles[i].setTexture(texture);
			particles[i].setPosition(400.0, 300.0);
			particles[i].init();
			particles[i].setId(i);
		}
	}

	void Emitter::start() {
		clock.restart();
		for (int i = 0; i < NUM_PARTICLES; i++) {
			particles[i].init();
		}
	}

	Emitter::~Emitter() {
		// TODO Auto-generated destructor stub
	}

	void Emitter::setRenderWindow(sf::RenderWindow* renWin) {
		renderWindow = renWin;
	}

	void Emitter::update() {
		for (int i = 0; i < NUM_PARTICLES; i++) {
			particles[i].update();
		}
		if (clock.getElapsedTime() > frequencyOfRelease) {

		}

	}

	void Emitter::draw() {
		for (int i = 0; i < NUM_PARTICLES; i++) {
			renderWindow->draw(particles[i]);
		}
	}

} /* namespace ic */
