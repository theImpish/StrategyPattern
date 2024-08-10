#pragma once

#include "SFML/Graphics.hpp"
#include "Vec2.h"

class Missile
{
private:
	Vec2 m_size;
	sf::Sprite m_sprite;

public:
	Missile(sf::Texture& texture);

	void display();
	void quack();
	void swim();

	void update();
};