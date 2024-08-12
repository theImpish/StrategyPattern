#pragma once
#pragma once

#include "Missile.h"
#include "Game.h"
#include "Vec2.h"

#include <memory>
#include <vector>
#include <string>
#include <map>

class Missile;
class Game;

typedef std::vector<std::shared_ptr<Missile>> MissileVec;
typedef std::map<std::string, MissileVec> MissileMap;


class EntityManager
{
	MissileVec m_missiles;
	MissileVec m_missilesToAdd;
	MissileMap m_missileMap;
	size_t m_totalMissiles = 0;

	void removeMissiles(MissileVec& vec);

	Game* m_game = nullptr;

public:

	EntityManager(Game* game);

	void update();

	std::shared_ptr<Missile> addMissile(const std::string& tag, const sf::Texture& texture, Vec2 pos);

	const MissileVec& getMissiles();
	const MissileVec& getMissiles(const std::string& tag);
};