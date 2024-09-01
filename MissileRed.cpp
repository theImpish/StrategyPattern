#include "MissileRed.h"

MissileRed::MissileRed(const sf::Texture& texture, const sf::Color& colour, size_t id) : Missile(texture, colour, id)
{
	tag = "Missile Red";
	setPosition(Vec2(200, 600));
}
