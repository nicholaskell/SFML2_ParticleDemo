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

//	sf::Texture Particle::texture;

	Particle::Particle() :
			sf::Sprite() {
		// TODO Auto-generated constructor stub
		init();

		pointOfOrigin = sf::Vector2f(100, 100);
		this->setOrigin(16.0, 16.0);
	}

	Particle::~Particle() {
		// TODO Auto-generated destructor stub
	}

	void Particle::init() {
//		srand((unsigned)time(0));
//
//		idNumber = name;
		gravity = 0.0001;
		alpha = 255.0;
		x = 400; //3.0*(float)rand()/(float)RAND_MAX;
		y = 300; //3.0*(float)rand()/(float)RAND_MAX;

		float dirVar = 1.0;

		directionX = (dirVar * (float) rand() / (float) RAND_MAX)
				- (dirVar / 2);
		directionY = (dirVar * (float) rand() / (float) RAND_MAX)
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
		update();

//		std::cout << "R- " << float(getColor().r) << std::endl;
//		std::cout << "G- " << float(getColor().g) << std::endl;
//		std::cout << "B- " << float(getColor().b) << std::endl;
//		std::cout << "alpha C- " << float(getColor().a) << std::endl;
//		std::cout << "alpha- " << alpha << std::endl;
//		std::cout << "RoD- "<<rateOfDeath << std::endl;

	}

	void Particle::respawn() {
		init();
	}


	void Particle::setDirection(float dx, float dy) {
		directionX = dx;
		directionY = dy;
	}

	void Particle::setDirection(sf::Vector2f dir) {
		setDirection(dir.x, dir.y);
	}

	void Particle::update() {
//		gravity += gravity;
//		gravity /= gravity;
//		gravity -= gravity;
//		y+=gravity;
		float nX = ((x-alpha)/alpha);
		gravity += nX/5.0;//*(sqrt(sin(nX+M_PI/2)));
//		y+=gravity;
		setPosition(x += directionX, (y += directionY)+gravity);
		if(idNumber == 1){
			std::cout <<"A:"<<alpha << "\tx:"<<x<<" \ty:"<<y <<" \tnX - "<<nX <<" \tG- "<<gravity<<std::endl;
		}

		sf::Color color = getColor();
		color.a = sf::Uint8(alpha-=rateOfDeath);



		if (alpha <= 1.0) {
			respawn();
		} else {

//			std::cout << "alpha C- " << float(getColor().a) << std::endl;
//			std::cout << "alpha- " << alpha << std::endl;
//			std::cout << "RoD- "<<rateOfDeath << std::endl;
			setColor(color);
		}
	}

	bool Particle::isAlive() {
		return TTL > 0;
	}

	int Particle::getTTL() const {
		return TTL;
	}

	void Particle::decrementTTL(int num) {
		TTL -= num;
	}

	void Particle::setTTL(int TTL) {
		this->TTL = TTL;
	}

} /* namespace ic */
