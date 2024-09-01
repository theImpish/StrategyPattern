#pragma once

//#include "Game.h"

#include "SFML/Graphics.hpp"
#include "Vec2.h"

#include <iostream>

class Missile
{
	friend class EntityManager;
private:

	Vec2 m_size;
	sf::Sprite m_sprite;
	sf::Texture m_texture;
	sf::RectangleShape m_rectangle;
	sf::Color m_colour;

	size_t m_id = 0;
	
	bool m_drawRectangle = false;
	bool m_isActive = true;

public:
	std::string tag = "missile";

private:
	void initSprite();
	void initSelector();
public:

	Missile();
	Missile(const sf::Texture& texture, const sf::Color& colour, size_t id);

	void init();
	void setPosition(Vec2 pos);

	void render(sf::RenderWindow& window);
	void select();
	void deselect();

	const sf::Sprite& getSprite();

	virtual const std::string getType();
};