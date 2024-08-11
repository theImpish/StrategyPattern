#include "Missile.h"


Missile::Missile(const size_t id, const std::string tag, const sf::Texture& texture, Vec2 pos)
	: m_id(id), m_tag(tag)
{
	m_size = Vec2((float)texture.getSize().x, (float)texture.getSize().y);
	m_sprite.setOrigin(m_size.x / 2, m_size.y);
	m_sprite.setTexture(texture);
	m_sprite.setPosition(pos.x, pos.y);
	//m_sprite.setTextureRect(sf::IntRect(0, 0, m_size.x, m_size.y));
}

void Missile::display(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}

void Missile::quack()
{
}

void Missile::swim()
{
}

const sf::Sprite& Missile::getSprite()
{
	return m_sprite;
}

void Missile::update(Vec2 pos)
{
	m_sprite.setPosition(pos.x, pos.y);
}