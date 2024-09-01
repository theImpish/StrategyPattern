#pragma once
#pragma once


#include "Assets.h"
#include "Entity.h"
#include "EntityManager.h"

#include <SFML/Graphics.hpp>


class Game
{
private:
	sf::RenderWindow m_window;
	std::shared_ptr<EntityManager> m_entityManager = nullptr;

	sf::Font m_font;
	sf::Text m_text;

	bool m_paused = false;
	bool m_running = true;
	int m_currentFrame = 0;

	Assets m_assets;
	std::shared_ptr<Entity> m_player;

public:
	int currentSelection = 0;

private:
	void init();
	void setPaused();

	void sMovement();
	void sUserInput();
	void sRender();

	void sEnemySpawner();
	void sCollision();

	void spawnPlayer();
	void spawnEnemy();

public:

	Game();

	void run();

	Assets& getAssets();
	sf::RenderWindow& getRenderWindow();
};
