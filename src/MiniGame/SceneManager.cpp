#include "SceneManager.h"
#include "GameManager.h"

SceneManager::SceneManager()
{

    m_sceneName[GameManager::GameState::MENU] = "Menu";
    m_sceneName[GameManager::GameState::STATION] = "Play";
    m_sceneName[GameManager::GameState::SETTING] = "Settings";
    m_sceneName[GameManager::GameState::LEVEL_1] = "Level1";
    m_sceneName[GameManager::GameState::GAMEOVER] = "GameOver";
    m_sceneName[GameManager::GameState::WIN] = "Win";

}

Scene* SceneManager::GetCurrentScene()
{
    return m_CurrentScene;
}

void SceneManager::ChangeScene(int scene)
{
    m_CurrentScene = m_SceneMap[scene];
}

void SceneManager::NewScene(std::string Name, int GameStateName)
{
    Scene* newScene = new Scene(Name, GameStateName);
    m_SceneMap[GameStateName] = newScene;
}