#include "Paddle.h"
#include "Game.h"
#include "DrawManager.h"
#include "InputManager.h"

Paddle::Paddle()
{
}


Paddle::~Paddle()
{
}

void Paddle::Initialise(int player, Ball* pBall)
{
  m_active = true;
  m_player = player;
  m_pBall = pBall;

  m_velocity = sf::Vector2f(0, 0);

  if (m_player == 0)
  {
    m_position = sf::Vector2f(50, Game::instance.GetWindow().getSize().y / 2);
  }
  else
  {
    m_position = sf::Vector2f(Game::instance.GetWindow().getSize().x - 65, Game::instance.GetWindow().getSize().y / 2);
  }
  
}

void Paddle::Update(float deltaTime)
{
  InputManager* pInputManager = InputManager::GetInstance();

  if (m_player == 0)
  {
    if (pInputManager->KeyDown(sf::Keyboard::W))
    {
      m_velocity.y = -200;
    }
    else if (pInputManager->KeyDown(sf::Keyboard::S))
    {
      m_velocity.y = 200;
    }
    else
    {
      m_velocity.y = 0;
    }
  }
  else if (m_player == 1)
  {
    if (pInputManager->KeyDown(sf::Keyboard::Up))
    {
      m_velocity.y = -200;
    }
    else if (pInputManager->KeyDown(sf::Keyboard::Down))
    {
      m_velocity.y = 200;
    }
    else
    {
      m_velocity.y = 0;
    }
  }
  else
  {
    if (m_pBall->GetPosition().y > m_position.y+100)
    {
      m_velocity.y = 200;
    }
    else if (m_pBall->GetPosition().y < m_position.y)
    {
      m_velocity.y = -200;
    }
  }

  m_position += m_velocity*deltaTime;

  ProcessCollision();
}

void Paddle::Draw()
{
  DrawManager* pDrawManager = DrawManager::GetInstance();

  pDrawManager->BasicRect(sf::FloatRect(m_position, sf::Vector2f(15, 100)), sf::Color::White);
}

void Paddle::ProcessCollision()
{

}