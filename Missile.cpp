#include "Missile.h"


Missile::Missile(sf::Texture& texture)
{
	m_size = Vec2((float)texture.getSize().x, (float)texture.getSize().y);
	m_sprite.setOrigin(m_size.x / 2, m_size.y);
	m_sprite.setTextureRect(sf::IntRect(0, 0, m_size.x, m_size.y));
}

void Missile::display()
{
}
