#include "Player.h"
#include "GameManager.h"
Player::Player()
{
	m_MaxHealth = 100;
	m_Health = m_MaxHealth;

    if (!m_Texture.loadFromFile("../../../src/MiniGame/ship_0000.png"))
    {
    }
    m_Sprite.setTexture(m_Texture);

    m_Sprite.setOrigin((float)m_Texture.getSize().x / 2.f, (float)m_Texture.getSize().y / 2.f);
    setPosition(500, 500);

}

void Player::Update(sf::Time deltaTime, const sf::RenderWindow& window)
{
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(m_Sprite, states);
}

void Player::Deplacement(sf::Vector2f direction, sf::Time deltaTime)
{
    this->move(direction.x * deltaTime.asMilliseconds(), direction.y * deltaTime.asMilliseconds());

}
void Player::Shoot()
{

	

	GameManager::GetInstance()->m_SceneManagerInstance->GetCurrentScene()->AddEntity<Bullet>();
}