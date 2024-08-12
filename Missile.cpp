#include "Missile.h"


Missile::Missile(Game* game, const size_t id, const std::string tag, const sf::Texture& texture, Vec2 pos)
	: m_game(game), m_id(id), m_tag(tag)
{
	m_size = Vec2((float)texture.getSize().x, (float)texture.getSize().y);
	m_sprite.setOrigin(m_size.x / 2, m_size.y);
	m_sprite.setTexture(m_game->getAssets().getTexture("Small Blue"));
	m_sprite.setPosition(pos.x, pos.y);

	m_rectangle.setSize(sf::Vector2f(m_size.x, m_size.y));
	m_rectangle.setOrigin(m_size.x / 2, m_size.y);
	m_rectangle.setPosition(m_sprite.getPosition());
	m_rectangle.setOutlineThickness(1);
	m_rectangle.setOutlineColor(m_game->getAssets().getColour("White"));
	m_rectangle.setFillColor(sf::Color::Transparent);
}

void Missile::display(sf::RenderWindow& window)
{
	window.draw(m_sprite);
	if (m_drawRectangle)
	{
		//std::cout << "Draw Rectangle" << '\n';
		window.draw(m_rectangle);
	}
}



void Missile::drawRectangle()
{
	m_drawRectangle = !m_drawRectangle;
	std::cout << m_drawRectangle << '\n';
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