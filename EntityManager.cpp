#include "EntityManager.h"

EntityManager::EntityManager(Game* game) : m_game(game)
{
}

void EntityManager::update()
{
	for (std::shared_ptr<Missile> e : m_missilesToAdd)
	{
		m_missiles.push_back(e);
		m_missileMap[e->m_tag].push_back(e);
	}

	m_missilesToAdd.clear();

	// remove dead entities from the vector of all entities
	removeMissiles(m_missiles);

	// remove dead entities from each vector in the entity map
	for (auto& [tag, missileVec] : m_missileMap)
	{
		removeMissiles(missileVec);
	}
}

void EntityManager::removeMissiles(MissileVec& vec)
{
	vec.erase(
		std::remove_if(vec.begin(), vec.end(), [](auto e) {return !e->m_isActive; })
		, vec.end());
}
std::shared_ptr<Missile> EntityManager::addMissile(const std::string& tag, const sf::Texture& texture, Vec2 pos)
{
	auto missile = std::shared_ptr<Missile>(new Missile(m_game, m_totalMissiles++, tag, texture, pos));

	m_missilesToAdd.push_back(missile);

	return missile;
}
const MissileVec& EntityManager::getMissiles()
{
	return m_missiles;
}

const MissileVec& EntityManager::getMissiles(const std::string& tag)
{
	if (m_missileMap.find(tag) != m_missileMap.end())
	{
		return m_missileMap.find(tag)->second;
	}
	else
	{
		MissileVec empty;
		return empty;
	}
}
