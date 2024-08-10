#pragma once


#include <memory>
#include <SFML/Graphics.hpp>

typedef std::map<std::string, sf::Font> Fonts;
typedef std::map<std::string, sf::Texture> Textures;
typedef std::map<std::string, sf::Color> Colours;

class Assets
{
private:
	Fonts m_fonts;
	Textures m_texture;
	Colours m_colours;

	void loadAssets();
	void addFont(std::string name, std::string path);
	void addTexture(std::string name, std::string path);
	void addColour(std::string name, uint32_t hex);
public:
	Assets();

	sf::Font getFont(std::string name);
	sf::Texture getTexture(std::string name);
	sf::Color getColours(std::string name);
};