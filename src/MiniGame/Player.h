#pragma once
#include "Character.h"
#include <SFML/Graphics.hpp>
#include "Bullet.h"
class Player : public Character
{
public:


	int m_Health;
	int m_MaxHealth;



	sf::Texture m_Texture;
	sf::Sprite m_Sprite;


	sf::Clock Clock;
	

	int m_PistolFireSpeed = 0;



	Player();

	void Init();
	void Update(sf::Time deltaTime, const sf::RenderWindow& window);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void Deplacement(sf::Vector2f direction, sf::Time deltaTime);

	void Shoot();

};