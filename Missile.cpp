#include "Missile.h"

Missile::Missile(const sf::Texture& texture, const sf::Color& colour, size_t id)
	:m_texture(texture), m_colour(colour), m_id(id)
{
	init();
}

Missile::Missile() {}

void Missile::init()
{
	initSprite();
	initSelector();
}

void Missile::initSprite()
{
	m_size = Vec2((float)m_texture.getSize().x, (float)m_texture.getSize().y);
	m_sprite.setOrigin(m_size.x / 2, m_size.y);
	m_sprite.setTexture(m_texture);
}

void Missile::setPosition(Vec2 pos)
{
	m_sprite.setPosition(pos.x, pos.y);
	m_rectangle.setPosition(m_sprite.getPosition());
}

void Missile::initSelector()
{
	m_rectangle.setSize(sf::Vector2f(m_size.x, m_size.y));
	m_rectangle.setOrigin(m_size.x / 2, m_size.y);
	m_rectangle.setOutlineThickness(1);
	m_rectangle.setOutlineColor(m_colour);
	m_rectangle.setFillColor(sf::Color::Transparent);
}

void Missile::render(sf::RenderWindow& window)
{
	window.draw(m_sprite);
	if (m_drawRectangle)
	{
		//std::cout << "Draw Rectangle" << '\n';
		window.draw(m_rectangle);
	}
}

void Missile::select()
{
	m_drawRectangle = true;
}

void Missile::deselect()
{
	m_drawRectangle = false;
}

const sf::Sprite& Missile::getSprite()
{
	return m_sprite;
}

const std::string Missile::getType()
{
	return "Base Class";
}
