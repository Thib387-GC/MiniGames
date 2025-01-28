#pragma once
#include <SFML/Graphics.hpp>
#include "SceneManager.h"
#include "DataManager.h"
#include "Player.h"

class GameManager
{
public:
	enum GameState
	{
		MENU,
		STATION,
		SETTING,
		LEVEL_1,
		EXIT,
		GAMEOVER,
		WIN
	};

	int m_GameState = MENU;


	static GameManager* m_Instance;
	Player* m_PlayerInstance;
	SceneManager* m_SceneManagerInstance;
	sf::Clock m_ClockTime;
	DataManager* m_DataManager;

	static GameManager* GetInstance();

	void InitGameManager();

	void Input(sf::Time deltatime , Player* player);


	int GameLoop();
};
