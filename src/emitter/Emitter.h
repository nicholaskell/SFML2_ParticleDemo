/*
 * Emitter.h
 *
 *  Created on: Apr 26, 2012
 *      Author: nick
 */

#ifndef EMITTER_H_
#define EMITTER_H_

#include "Particle.h"

#define NUM_PARTICLES 100

namespace ic {

	class Emitter {
		public:
			Emitter();
			virtual ~Emitter();
			void update();
			void start();
			void draw();
			void setRenderWindow(sf::RenderWindow* renWin);

		protected:
//			Particle particle;
			sf::Texture texture;
			sf::Time frequencyOfRelease;
			sf::Clock clock;
			sf::RenderWindow* renderWindow;
			Particle particles[NUM_PARTICLES];
	};

} /* namespace ic */
#endif /* EMITTER_H_ */
