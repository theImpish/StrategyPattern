#pragma once

#include "SFML/Graphics.hpp"
#include "Vec2.h"

class Missile
{
	friend class EntityManager;
private:

	bool m_isActive = true;
	size_t m_id = 0;
	std::string m_tag = "missile";

	Vec2 m_size;
	sf::Sprite m_sprite;

public:

	Missile(const size_t id, const std::string tag, const sf::Texture& texture, Vec2 pos);

	void display(sf::RenderWindow& window);
	void quack();
	void swim();

	const sf::Sprite& getSprite();

	void update(Vec2 pos);
};