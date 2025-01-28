#pragma once
#include "Movable.h"
#include "IAttacker.h"
#include "Collidable.h"
#include "Entity.h"
#include <SFML/Graphics.hpp>

class Bullet: public Collidable, public IAttacker, public Entity
{
protected:


	sf::Texture m_Texture;
	sf::Sprite m_Sprite;

	bool m_IsExploding = false;

	int m_AnimationFrame = 0;

	sf::Vector2f m_DirectionBullet;
	int m_AngleRotation;

public:

	Bullet();
	void init(sf::Vector2f DirectionBullet, int AngleRotation);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void Movint(sf::Time deltaTime);
	void Update(sf::Time deltaTime, const sf::RenderWindow& window);
	void attack(Alive*);
	~Bullet();
};