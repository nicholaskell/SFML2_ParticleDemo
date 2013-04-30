/*
 * Emitter.cpp
 *
 *  Created on: Apr 26, 2012
 *      Author: nick
 */

#include "Emitter.h"

#include <iostream>
#include <math.h>

namespace ic {

	Emitter::Emitter() {
		sinAdjust = 1;
		percentOfDuty = 0.1;
		// TODO Auto-generated constructor stub
		texture.loadFromFile("media/particle.png");
//		Particle::texture = texture;
		frequencyOfRelease = sf::milliseconds(70);
//		particle.setPosition(100, 100);

		emitterPoint.x = 400;
		emitterPoint.y = 300;
		numberOfParticles = 0;
//		setNumberOfParticles(100);
particles = NULL;

	}

	Emitter::~Emitter() {
		// TODO Auto-generated destructor stub
	}

	void Emitter::setDuty(float duty) {
		percentOfDuty = duty;
	}

	void Emitter::start() {
		clock.restart();
		//particles = new Particle[100];

	}


	void Emitter::setNumberOfParticles(int nums) {

		sf::Vector2f dir;
//
	//	delete particles;
	if(particles){
		delete[] particles;
	}

		particles = new Particle[nums];

		numberOfParticles = nums;
		for (int i = 0; i < numberOfParticles; i++) {
			//			texture.loadFromFile("media/particle.png");
//			particles[i] = new Particle();
			particles[i].setTexture(texture);
			//			particles[i].setPosition(400.0, 300.0);
			//			particles[i].init();
			particles[i].setSpawnOrigin(emitterPoint);
			particles[i].setId(i);
			dir.x += (float) rand() / (float) RAND_MAX;
			dir.y += (float) rand() / (float) RAND_MAX;
			particles[i].setDirection(dir);
		}
	}

	void Emitter::setRenderWindow(sf::RenderWindow* renWin) {
		renderWindow = renWin;
	}

	void Emitter::update() {
		int targetAliveParticles = int(float(numberOfParticles) * percentOfDuty);
		std::cout << "Number " << targetAliveParticles << "\tNoPA:" <<numberOfParticlesAlive <<"\t Ex:" << numberOfParticlesAlive-targetAliveParticles <<"\t";
		int aliveParticles = 0;
		int revivedParticles;
		for (int i = 0; i < numberOfParticles; i++) {

			if (particles[i].isAlive()) {
				aliveParticles++;
			}

			if (int(targetAliveParticles) < numberOfParticlesAlive+revivedParticles) {
				particles[i].update(false);
			} else {
//				if(int(emitterPoint.x * 10000.0)%1){
					if(!particles[i].isAlive()){
						revivedParticles++;
					}
					particles[i].update(true);
//					std::cout << "x";

//				}

			}

			emitterPoint.x += 0.05;

			particles[i].setSpawnOrigin(emitterPoint);
			if (emitterPoint.x > renderWindow->getSize().x) {
				emitterPoint.x = 0;
			}
			if (emitterPoint.y > renderWindow->getSize().y) {
				emitterPoint.y = 0;

			}
		}
		std::cout << std::endl;
		numberOfParticlesAlive = aliveParticles;
		sinAdjust += 0.1;
		if (sinAdjust > 100.0) {
			sinAdjust = 1.0;
		}
//		setDuty(sinAdjust);

		percentOfDuty += 0.001;
		if (percentOfDuty > 1.0) {
			percentOfDuty = 0.1;
		}

		if (clock.getElapsedTime() > frequencyOfRelease) {

		}

	}

	void Emitter::draw() {
		for (int i = 0; i < numberOfParticles; i++) {
			if(particles[i].isAlive()){
				renderWindow->draw(particles[i]);
			}
		}
	}

} /* namespace ic */
