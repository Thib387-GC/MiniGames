#include "Bullet.h"
#include "GameManager.h"

Bullet::Bullet()
{

    init(sf::Vector2f(0,0.7f),0);
}

void Bullet::init(sf::Vector2f DirectionBullet, int AngleRotation)
{
    if (!m_Texture.loadFromFile("../../../res/OTHER/laserGreen11.png"))
    {
        std::cout << "error";
    };



    m_Sprite.setTexture(m_Texture);
    m_Sprite.setOrigin(GameManager::GetInstance()->m_PlayerInstance->getOrigin());
    m_Sprite.setPosition(GameManager::GetInstance()->m_PlayerInstance->getPosition().x - 1, GameManager::GetInstance()->m_PlayerInstance->getPosition().y - 25);

    m_HitBox = new sf::CircleShape();
    m_HitBox->setRadius(5.f);

    float hitboxX = m_Sprite.getPosition().x;
    float hitboxY = m_Sprite.getPosition().y - (m_Texture.getSize().y / 2.f) - m_HitBox->getRadius();

    m_HitBox->setPosition(hitboxX, hitboxY);

    m_DirectionBullet = DirectionBullet;
    m_Sprite.setRotation(AngleRotation);
}

void Bullet::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(m_Sprite, states);
}

void Bullet::Movint(sf::Time deltaTime)
{
        m_Sprite.move(m_DirectionBullet.x * (float)deltaTime.asMilliseconds(), -(m_DirectionBullet.y) * (float)deltaTime.asMilliseconds());
}



void Bullet::Update(sf::Time deltaTime, const sf::RenderWindow& window)
{
   
  
        Movint(deltaTime);
    
}

void Bullet::attack(Alive* ennemie)
{

}



Bullet::~Bullet()
{
    if (m_HitBox != nullptr)
    {
        delete m_HitBox;
        m_HitBox = nullptr;
    }
}