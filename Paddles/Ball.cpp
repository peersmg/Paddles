#include "Ball.h"
#include "Game.h"
#include <time.h>

Ball::Ball()
{
}


Ball::~Ball()
{
}

void Ball::Initialise()
{
  m_active = true;
  m_velocity = sf::Vector2f(500, (rand()%300)-150);
  m_position = sf::Vector2f(Game::instance.GetWindow().getSize().x / 2, Game::instance.GetWindow().getSize().y / 2);
  m_rect = sf::FloatRect(m_position, sf::Vector2f(15, 15));
}

void Ball::Update(float deltaTime)
{
  if (m_position.y + m_rect.height > Game::instance.GetWindow().getSize().y || m_position.y < 0)
  {
    m_velocity.y = -m_velocity.y;
  }

  m_position += m_velocity*deltaTime;
  m_rect = sf::FloatRect(m_position, sf::Vector2f(15, 15));
}

void Ball::Draw()
{
  DrawManager* pDrawManager = DrawManager::GetInstance();

  pDrawManager->BasicRect(m_rect, sf::Color::White);
}

sf::Vector2f Ball::GetPosition()
{
  return m_position;
}

sf::FloatRect Ball::GetRect()
{
  return m_rect;
}

void Ball::SetVelocity(sf::Vector2f newVelocity)
{
  m_velocity = newVelocity;
}

sf::Vector2f Ball::GetVelocity()
{
  return m_velocity;
}

void Ball::Deactivate()
{
  m_active = false;
}
