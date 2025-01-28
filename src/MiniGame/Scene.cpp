#include "Scene.hpp"

Scene::Scene(std::string Name, int GameStateName)
{
    m_ArreaLimitPlay = sf::Vector2i(1920,1080);
}

void Scene::Update(sf::Time deltaTime, const sf::RenderWindow& window)
{


    for (int i = 0; i < m_EntityList.size(); i++)
    {
        m_EntityList[i]->Update(deltaTime, window);
    }



}

void Scene::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (int i = 0; i < m_EntityList.size(); i++)
    {
        target.draw(*m_EntityList[i], states);
    }

}




void Scene::RemoveAnEntity(Entity* entityToRemove)
{
    for (int i = 0; i < m_EntityList.size(); ++i)
    {
        if (m_EntityList[i] == entityToRemove)
        {
            m_EntityList.erase(m_EntityList.begin() + i);
            delete entityToRemove;
            return;
        }
    }
}

Scene::~Scene()
{
}
