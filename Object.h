#ifndef OBJECT_H
#define OBJECT_H

#include <SFML\Graphics.hpp>

class Object {
protected:
	sf::Vector2f velocity;
	sf::Vector2f position;
	sf::Vector2f accelleration;
	float mass;

public:
	Object(sf::Vector2f position, sf::Vector2f velocity);

	virtual void update(float dt, float gravity) = 0;
	virtual void draw(sf::RenderWindow &window) = 0;

	sf::Vector2f getVelocity() const;
	sf::Vector2f getPosition() const;

	void setVelocity(sf::Vector2f velocity);
	void setPosition(sf::Vector2f position);
	

};

#endif // !OBJECT_H
