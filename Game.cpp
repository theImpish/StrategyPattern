#include "Game.h"

#include <iostream>
#include <fstream>

#include "GameConsts.h"

Game::Game()
{
	m_entityManager = std::make_shared<EntityManager>(this);
	init();
}

void Game::init()
{
	m_assets;
	
	int width = 1280, height = 720, frameLimit = 0;
	bool fullScreen = false;

	m_window.create(sf::VideoMode(width, height), "SFML Template", (fullScreen) ? sf::Style::Fullscreen : sf::Style::Default);
	m_window.setFramerateLimit(frameLimit);

	std::srand(std::time(nullptr));

	spawnPlayer();
	spawnEnemy();
}

void Game::run()
{
	while (m_running)
	{
		m_entityManager->update();

		if (!m_paused)
		{
			sEnemySpawner();
			sMovement();
			sCollision();
		}

		sUserInput();
		sRender();

		m_currentFrame++;
	}
}

void Game::setPaused()
{
	m_paused = !m_paused;
}

void Game::spawnPlayer()
{
	//m_entityManager->addMissile("Small Blue", m_assets.getTexture("Small Blue"), Vec2(100,100));
	m_entityManager->addMissile(std::make_shared<MissileBlue>(m_assets.getTexture("Small Blue")
		, sf::Color(Game_Colours::SILVER)
		, m_entityManager->m_totalMissiles++));
	m_entityManager->addMissile(std::make_shared<MissileRed>(m_assets.getTexture("Medium Red")
		, sf::Color(Game_Colours::TIMBERWOLF)
		, m_entityManager->m_totalMissiles++));
	
}

void Game::spawnEnemy()
{

}

void Game::sMovement()
{

}

void Game::sCollision()
{

}

void Game::sEnemySpawner()
{
	//if (m_currentFrame - m_lastEnemySpawnTime > m_enemyConfig.SI)
	//{
	spawnEnemy();
	//}

}

void Game::sRender()
{

	m_window.clear(sf::Color(Game_Colours::IMPERIAL_RED));

	//m_text = sf::Text("Score: " + std::to_string(m_score), m_font, m_fontConfig.S);
	//m_text.setPosition(10, 10);
	//m_window.draw(m_text);

	for (auto& m : m_entityManager->getMissiles())
	{
		m->render(m_window);
		//m_window.draw(m->getSprite());
	}

	m_window.display();
}

void Game::sUserInput()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		// this event triggers when the window is closed
		if (event.type == sf::Event::Closed)
		{
			m_running = false;
		}

		// this event is triggered when a key is pressed
		if (event.type == sf::Event::KeyPressed)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::Escape:
				m_running = false;
				break;
			case sf::Keyboard::W:
				break;
			case sf::Keyboard::S:
				break;
			case sf::Keyboard::A:
				if (currentSelection > 0) 
				{
					currentSelection--;
					m_entityManager->selectMissile();
					std::cout << "current selection: " << currentSelection << '\n';
				}
				break;
			case sf::Keyboard::D:
				if (currentSelection < m_entityManager->m_totalMissiles - 1) 
				{
					currentSelection++;
					m_entityManager->selectMissile();
					std::cout << "Total: " << m_entityManager->m_totalMissiles << " current selection: " << currentSelection << '\n';
				}
				break;
			case sf::Keyboard::P:
				setPaused();
			case sf::Keyboard::R:
				//m_entityManager->getMissiles()[currentSelection]->drawRectangle();
				break;
			default: break;
			}
		}

		// this event is triggered when a key is released
		if (event.type == sf::Event::KeyReleased)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::W:
				break;
			case sf::Keyboard::S:
				break;
			case sf::Keyboard::A:
				break;
			case sf::Keyboard::D:
				break;
			default: break;
			}
		}

		// this event is triggered when a key is released


		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				std::cout << "Right Mouse Button Clicked at (" << event.mouseButton.x << " " << event.mouseButton.y << ")\n";
			}

			if (event.mouseButton.button == sf::Mouse::Right)
			{
				std::cout << "Right Mouse Button Clicked at (" << event.mouseButton.x << " " << event.mouseButton.y << ")\n";
			}
		}

	}

}

Assets& Game::getAssets()
{
	return m_assets;
}

sf::RenderWindow& Game::getRenderWindow()
{
	return m_window;
}

