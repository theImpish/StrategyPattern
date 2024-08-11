#pragma once
#pragma once

#include "Missile.h"

#include <memory>
#include <vector>
#include <string>
#include <map>


typedef std::vector<std::shared_ptr<Missile>> MissileVec;
typedef std::map<std::string, MissileVec> MissileMap;

class EntityManager
{
	MissileVec m_missiles;
	MissileVec m_missilesToAdd;
	MissileMap m_missileMap;
	size_t m_totalMissiles = 0;

	void removeMissiles(MissileVec& vec);

public:

	EntityManager();

	void update();

	std::shared_ptr<Missile> addMissile(const std::string& tag, const sf::Texture& texture, Vec2 pos);

	const MissileVec& getMissiles();
	const MissileVec& getMissiles(const std::string& tag);
};