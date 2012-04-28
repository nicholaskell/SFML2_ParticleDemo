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
			void setLives(int);
			void update(bool);
			void init(sf::Vector2f);
			void setId(int id){idNumber = id;};
			void setTimeToLive(sf::Time);
			void setDirection(sf::Vector2f);
			void setWind(float);
			void setGravity(float);
			void setAlpha(float);
			void setSpawnOrigin(sf::Vector2f);
			bool isAlive();

		protected:
			void respawn();
			int lives;
			bool flaggedToDie;
			bool flaggedToRespawn;
			sf::Clock lifeClock;
			int idNumber;
			sf::Time timeToLive;
			sf::Vector2f environment;
			float alpha;
			sf::Vector2f coords;
			sf::Vector2f velocity;
			sf::Vector2f direction;
			sf::Vector2f pointOfOrigin;
			float rateOfDeath;

	};

} /* namespace ic */
#endif /* PARTICLE_H_ */
