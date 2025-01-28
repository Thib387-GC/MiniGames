#pragma once
#include <vector>
#include "Entity.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>      
#include <sstream>

struct MobInfoSpawn
{
	int Time;
	sf::Vector2f Position;
	int Pattern;
	int Type;
	float TimeScreen;
};

class Scene :public sf::Drawable
{
public:

	sf::Clock* m_clock = nullptr;
	bool m_player;

	std::vector<Entity*> m_EntityList;

	std::map<int, MobInfoSpawn> m_ListeMobInfo;



	float m_Score = 0;
	



	int GameStateNameLink = 0;

	sf::Vector2i m_ArreaLimitPlay;

	Scene(std::string Name, int GameStateName);

	void Update(sf::Time deltaTime, const sf::RenderWindow& window);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;


	
	template<typename T>
	T* AddEntity();

	template<typename T>
	std::vector<T*> GetEntity();

	template<typename T>
	void RemoveAnEntityType();


	void RemoveAnEntity(Entity* entityToRemove);
	
	~Scene();
};

template<typename T>
inline T* Scene::AddEntity()
{

	T* tempEntity = new T();

	m_EntityList.push_back(tempEntity);
	return tempEntity;
}

template<typename T>
inline std::vector<T*> Scene::GetEntity()
{
	std::vector<T*> array;
	for (int i = 0; i < m_EntityList.size(); i++)
	{
		if (dynamic_cast<T>(m_EntityList[i]) != nullptr) {
			array->push_back(m_EntityList[i]);
		}
	}
	return array;

}

template<typename T>
inline void Scene::RemoveAnEntityType()
{
	std::vector<T*> array = GetEntity<T>();
	for (int i = 0; i < array->size(); i++)
	{
		delete array[i];
	}

}


