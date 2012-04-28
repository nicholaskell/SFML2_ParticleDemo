/*
 * Particle.cpp
 *
 *  Created on: Apr 26, 2012
 *      Author: nick
 */
#include <iostream>
#include <math.h>

#include "Particle.h"

namespace ic {

//	sf::Texture Particle::partTexture;

	Particle::Particle() :
			sf::Sprite() {
		srand((unsigned) time(0));
		respawn();
		flaggedToDie = false;

		pointOfOrigin = sf::Vector2f(100, 100);
		this->setOrigin(16.0, 16.0);
	}

	Particle::~Particle() {

	}

	bool Particle::isAlive() {
		bool alive = true;

		if (alpha <= 1.0) {
//					respawn();
			alive = false;
		} else if (timeToLive < lifeClock.getElapsedTime()) {
//					respawn();
			alive = false;
		} else {

		}


		return alive;
	}

	void Particle::init(sf::Vector2f newPoO) {
		pointOfOrigin = newPoO;
		lifeClock.restart();
		environment.y = 0.001;
		environment.x = 0.001;
		alpha = 255.0;
		coords = pointOfOrigin;
		float dirVar = 1.0;

		timeToLive = sf::milliseconds(
				((5000 * (float) rand() / (float) RAND_MAX)));

		direction.x = (dirVar * (float) rand() / (float) RAND_MAX)
				- (dirVar / 2);
		direction.y = (dirVar * (float) rand() / (float) RAND_MAX)
				- (dirVar / 2);

		rateOfDeath = 1.0 * (float) rand() / (float) RAND_MAX + 0.1;

		this->setRotation(rateOfDeath);
		this->setScale(rateOfDeath, rateOfDeath);

		sf::Uint8 r = sf::Uint8(255 * (float) rand() / (float) RAND_MAX);
		sf::Uint8 g = sf::Uint8(255 * (float) rand() / (float) RAND_MAX);
		sf::Uint8 b = sf::Uint8(255 * (float) rand() / (float) RAND_MAX);
		alpha = 255.0;
		sf::Uint8 a = sf::Uint8(alpha);

		sf::Color color(r, g, b, 255);
		this->setColor(color);
		update(true);

	}

	void Particle::respawn() {
		flaggedToDie = false;
		flaggedToRespawn = false;
		init(pointOfOrigin);
	}

	void Particle::setSpawnOrigin(sf::Vector2f poo) {
		pointOfOrigin = poo;
	}

	void Particle::setDirection(sf::Vector2f dir) {
		environment = dir;
	}

	void Particle::setTimeToLive(sf::Time ttl) {
		timeToLive = ttl;
	}

	void Particle::setWind(float wind) {
		environment.x = wind;
	}

	void Particle::setGravity(float gravity) {
		environment.y = gravity;
	}

	void Particle::setAlpha(float al) {
		alpha = al;
	}

	void Particle::update(bool resp) {
		if(resp){
			flaggedToRespawn = true;
		}else{
			flaggedToDie = true;
		}
		float nX = (float) rand() / (float) RAND_MAX; //((coords.x - alpha) / alpha);
		environment.y += nX; //Gravity
		environment.x += nX * 0.1; // / 1.0; //Wind
		coords += direction; //
//		coords+=environment;

		setPosition(coords + environment);

//		if (idNumber != 1) {
//			std::cout << "A:" << alpha << "\tx:" << coords.x << " \ty:"
//					<< environment.x << " \tnX - " << nX << " \tG- "
//					<< environment.y << std::endl;
//		}

		sf::Color color = getColor();
		color.a = sf::Uint8(alpha -= rateOfDeath);


		setColor(color);

		if (isAlive()) {
		}

		if (!isAlive() && flaggedToDie) {
			color.a = 0;
			setColor(color);
//			respawn();
		}
		if(!isAlive() && !flaggedToDie){
//			setColor(color);
			respawn();
		}

		if(!isAlive() && resp){
			respawn();
		}
//		if(!isAlive() && flaggedToRespawn){
//			flaggedToRespawn = false;
//		}

//		if(!isAlive() && flaggedToDie){
////			flaggedToRespawn = true;
////			respawn();
//		}
	}

} /* namespace ic */
