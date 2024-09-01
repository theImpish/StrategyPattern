#pragma once

#include <memory>
#include <SFML/Graphics.hpp>

typedef std::map<std::string, sf::Font> Fonts;
typedef std::map<std::string, sf::Texture> Textures;

class Assets
{
private:
	Fonts m_fonts;
	Textures m_texture;

	void loadAssets();
	void addFont(std::string name, std::string path);
	void addTexture(std::string name, std::string path);
public:

	Assets();

	const sf::Font& getFont(std::string name);
	const sf::Texture& getTexture(std::string name);
};