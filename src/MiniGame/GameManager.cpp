#include "GameManager.h"

GameManager* GameManager::m_Instance = nullptr;

GameManager* GameManager::GetInstance()
{
    if (m_Instance == nullptr)
    {
        m_Instance = new GameManager();
    }
    return m_Instance;
}

void GameManager::InitGameManager()
{
}

void GameManager::Input(sf::Time deltatime, Player* player)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
        if (player->getPosition().y >= 0)
        {
            player->Deplacement({ 0, -0.5f }, deltatime);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        if (player->getPosition().y <= m_Instance->m_SceneManagerInstance->GetCurrentScene()->m_ArreaLimitPlay.y)
        {
            player->Deplacement({ 0, 0.5f }, deltatime);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        if (player->getPosition().x >= 0)
        {
            player->Deplacement({ -0.5f, 0 }, deltatime);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        if (player->getPosition().x <= m_Instance->m_SceneManagerInstance->GetCurrentScene()->m_ArreaLimitPlay.x)
        {
            player->Deplacement({ 0.5f, 0 }, deltatime);
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        
        
            m_Instance->m_PlayerInstance->Shoot();
        
        
    }

}





int GameManager::GameLoop()
{
    m_Instance->InitGameManager();
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Squadron 24" );
    window.setFramerateLimit(30);
    sf::Clock Clock;
    GameManager::GetInstance()->m_ClockTime = Clock;


    sf::Time deltatime;
    deltatime = Clock.restart();


    m_Instance->m_PlayerInstance = m_Instance->m_SceneManagerInstance->GetCurrentScene()->AddEntity<Player>();

    m_Instance->m_SceneManagerInstance = new SceneManager();
    m_Instance->m_SceneManagerInstance->NewScene(m_Instance->m_SceneManagerInstance->m_sceneName[MENU], GameManager::MENU);
    m_Instance->m_SceneManagerInstance->ChangeScene(MENU);

   
   


    while (window.isOpen()) {
        deltatime = Clock.restart();
        sf::Event event;
        Input(deltatime, m_Instance->m_PlayerInstance);

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                return 0;
            }
            if (event.type == sf::Event::Resized)
            {
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                window.setView(sf::View(visibleArea));
            }
        }

        m_Instance->m_SceneManagerInstance->GetCurrentScene()->Update(deltatime, window);

        window.clear(sf::Color(2, 14, 65)); // Print le background avec la couleurs bleu

        window.draw(*m_Instance->m_SceneManagerInstance->GetCurrentScene());

        window.display();

        if (m_Instance->m_GameState == EXIT)
        {
            return 0;
        }
    }
    

    return 0;
}
