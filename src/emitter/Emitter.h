/*
 * Emitter.h
 *
 *  Created on: Apr 26, 2012
 *      Author: nick
 */

#ifndef EMITTER_H_
#define EMITTER_H_

#include "Particle.h"

#define NUM_PARTICLES 1000

namespace ic {

	class Emitter {
		public:
			Emitter();
			virtual ~Emitter();
			void update();
			void start();
			void draw();
			void setRenderWindow(sf::RenderWindow* renWin);
			void setNumberOfParticles(int);
			void setDuty(float);

		protected:
			int numberOfParticlesAlive;
			int numberOfParticles;
			float sinAdjust;
			sf::Vector2f emitterPoint;
			sf::Texture texture;
			sf::Time frequencyOfRelease;
			sf::Clock clock;
			sf::RenderWindow* renderWindow;
			Particle* particles;
			float percentOfDuty;
	};

} /* namespace ic */
#endif /* EMITTER_H_ */
