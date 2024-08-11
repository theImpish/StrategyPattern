#include "Assets.h"

#include <iostream>

Assets::Assets()
{
	loadAssets();
}

const sf::Font& Assets::getFont(std::string name)
{
	return m_fonts.find(name)->second;
}

const sf::Texture& Assets::getTexture(std::string name)
{
	return m_texture.find(name)->second;
}

const sf::Color& Assets::getColour(std::string name)
{
	return m_colours.find(name)->second;
}

void Assets::loadAssets()
{

	std::map<std::string, std::string> fonts
	{
		 {"bold", "JetBrainsMonoNLNerdFont-Bold.ttf" }
		,{"light", "JetBrainsMonoNLNerdFont-ExtraLight.ttf" }
		,{"regular", "JetBrainsMonoNLNerdFont-Regular.ttf" }
	};

	for (const auto& [name, path] : fonts)
	{
		addFont(name, "assets/" + path);
	}

	std::map<std::string, std::string> textures
	{
		 {"Small Blue","spaceMissiles_001.png"}
		,{"Medium Red","spaceMissiles_006.png"}
		,{"Big Orange","spaceMissiles_011.png"}
		//,{"","spaceMissiles_016.png"}
		//,{"","spaceMissiles_021.png"}
		//,{"","spaceMissiles_026.png"}
		//,{"","spaceMissiles_031.png"}
		//,{"","spaceMissiles_036.png"}
		//,{"","spaceMissiles_002.png"}
		//,{"","spaceMissiles_007.png"}
		//,{"","spaceMissiles_012.png"}
		//,{"","spaceMissiles_017.png"}
		//,{"","spaceMissiles_022.png"}
		//,{"","spaceMissiles_027.png"}
		//,{"","spaceMissiles_032.png"}
		//,{"","spaceMissiles_037.png"}
		//,{"","spaceMissiles_003.png"}
		//,{"","spaceMissiles_008.png"}
		//,{"","spaceMissiles_013.png"}
		//,{"","spaceMissiles_018.png"}
		//,{"","spaceMissiles_023.png"}
		//,{"","spaceMissiles_028.png"}
		//,{"","spaceMissiles_033.png"}
		//,{"","spaceMissiles_038.png"}
		//,{"","spaceMissiles_004.png"}
		//,{"","spaceMissiles_009.png"}
		//,{"","spaceMissiles_014.png"}
		//,{"","spaceMissiles_019.png"}
		//,{"","spaceMissiles_024.png"}
		//,{"","spaceMissiles_029.png"}
		//,{"","spaceMissiles_034.png"}
		//,{"","spaceMissiles_039.png"}
		//,{"","spaceMissiles_005.png"}
		//,{"","spaceMissiles_010.png"}
		//,{"","spaceMissiles_015.png"}
		//,{"","spaceMissiles_020.png"}
		//,{"","spaceMissiles_025.png"}
		//,{"","spaceMissiles_030.png"}
		//,{"","spaceMissiles_035.png"}
		//,{"","spaceMissiles_040.png"}
	};

	for (const auto& [name, path] : textures)
	{
		addTexture(name, "assets/" + path);
	}

	std::map<std::string, uint32_t> colours
	{
	  {"Night",0x0b090aff}
	 ,{"Eerie black",0x161a1dff}
	 ,{"Blood red",0x660708ff}
	 ,{"Cornell red",0xa4161aff}
	 ,{"Cornell red 2",0xba181bff}
	 ,{"Imperial red",0xe5383bff}
	 ,{"Silver",0xb1a7a6ff}
	 ,{"Timberwolf",0xd3d3d3ff}
	 ,{"White smoke",0xf5f3f4ff}
	 ,{"White",0xffffffff}
	};

	for (const auto& [name, hex] : colours)
	{
		addColour(name, hex);
	}
}

void Assets::addFont(std::string name, std::string path)
{
	sf::Font font;

	if (!font.loadFromFile(path))
	{
		std::cout << "Could not load font from file: " << path << std::endl;
	}

	m_fonts[name] = font;
}

void Assets::addTexture(std::string name, std::string path)
{
	sf::Texture texture;

	if (!texture.loadFromFile(path))
	{
		std::cout << "Could not load texture from file: " << path << std::endl;
	}

	m_texture[name] = texture;
}

void Assets::addColour(std::string name, uint32_t hex)
{
	sf::Color colour(hex);

	m_colours[name] = colour;
}
