#pragma once

#include "Game.h"

#include "SFML/Graphics.hpp"
#include "Vec2.h"

#include <iostream>

class Game;

class Missile
{
	friend class EntityManager;
private:

	bool m_isActive = true;
	bool m_drawRectangle = true;
	size_t m_id = 0;
	std::string m_tag = "missile";

	Vec2 m_size;
	sf::Sprite m_sprite;
	sf::RectangleShape m_rectangle;

	Game* m_game = nullptr;

public:

	Missile(Game* game, const size_t id, const std::string tag, const sf::Texture& texture, Vec2 pos);

	void display(sf::RenderWindow& window);
	void drawRectangle();
	void swim();

	const sf::Sprite& getSprite();

	void update(Vec2 pos);
};