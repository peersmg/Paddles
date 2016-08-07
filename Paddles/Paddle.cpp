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
  
  m_rect = sf::FloatRect(m_position, sf::Vector2f(15, 100));
}

void Paddle::Update(float deltaTime)
{
  InputManager* pInputManager = InputManager::GetInstance();

  ProcessCollision();

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
    if (m_pBall->GetPosition().y + (m_pBall->GetRect().height / 2) > m_position.y + 20)
    {
      m_velocity.y = 250;
    }
    else if (m_pBall->GetPosition().y + (m_pBall->GetRect().height / 2) < m_position.y+(m_rect.height/2)-20)
    {
      m_velocity.y = -250;
    }
  }

  m_position += m_velocity*deltaTime;

  m_rect = sf::FloatRect(m_position, sf::Vector2f(15, 100));
}

void Paddle::Draw()
{
  DrawManager* pDrawManager = DrawManager::GetInstance();

  pDrawManager->BasicRect(m_rect, sf::Color::White);
}

void Paddle::ProcessCollision()
{
  // Check if rects intersect
  if (m_rect.intersects(m_pBall->GetRect()))
  {
    // The distance from the center of the paddle and the center of the ball
    float posPercent = (((m_pBall->GetPosition().y+(m_pBall->GetRect().height/2)) - m_position.y)/(m_rect.height/2))-1;
    float yAcceleration = 200 * posPercent;
    float xAcceleration = 200 * abs(posPercent);

    std::cout << "posPercent: " << posPercent << "\n";

    m_pBall->SetVelocity(sf::Vector2f(-(m_pBall->GetVelocity().x + xAcceleration), m_pBall->GetVelocity().y + yAcceleration));
  }
}