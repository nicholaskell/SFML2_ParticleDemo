/*
 * Particle.h
 *
 *  Created on: Apr 26, 2012
 *      Author: nick
 */

#ifndef PARTICLE_H_
#define PARTICLE_H_

#include <SFML/Graphics.hpp>

namespace ic {

	class Particle: public sf::Sprite {
		public:
			Particle();
			virtual ~Particle();
//			static void setTexture(sf::Texture);
			bool isAlive();
			void decrementTTL(int num = 1);
			int getTTL() const;
			void setTTL(int);
			void update();
			void setDirection(float,float);
			void setDirection(sf::Vector2f);
			void setPointOfOrigin(sf::Vector2f);
			void setPointOfOrigin(float,float);

			void init();
			void setId(int id){idNumber = id;};

		protected:
			int idNumber;
			float gravity;
			void respawn();
			sf::Texture texture;
			bool isVisible;
			float alpha;
			float x,y;
			float velocity;
			int TTL;
			float directionX,directionY;
			sf::Vector2f pointOfOrigin;
			float rateOfDeath;

	};

} /* namespace ic */
#endif /* PARTICLE_H_ */
