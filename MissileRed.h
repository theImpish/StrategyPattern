#pragma once

#include "Missile.h"

#include "Game.h"
#include "SFML/Graphics.hpp"
#include "Vec2.h"

#include <iostream>

class Game;

class MissileRed : public Missile
{
	//friend class EntityManager;
private:


public:
	MissileRed(const sf::Texture& texture, const sf::Color& colour, size_t id);
};