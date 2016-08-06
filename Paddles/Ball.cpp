#include "Ball.h"
#include "Game.h"

Ball::Ball()
{
}


Ball::~Ball()
{
}

void Ball::Initialise()
{
  m_active = true;
  m_velocity = sf::Vector2f(200,100);
  m_position = sf::Vector2f(Game::instance.GetWindow().getSize().x / 2, Game::instance.GetWindow().getSize().y / 2);
}

void Ball::Update(float deltaTime)
{
  m_position += m_velocity*deltaTime;
}

void Ball::Draw()
{
  DrawManager* pDrawManager = DrawManager::GetInstance();

  pDrawManager->BasicRect(sf::FloatRect(m_position, sf::Vector2f(15, 15)), sf::Color::White);
}

sf::Vector2f Ball::GetPosition()
{
  return m_position;
}