#include "PaddlesManager.h"
#include "Game.h"
#include "DrawManager.h"
#include <string>

PaddlesManager::PaddlesManager()
{
}

PaddlesManager::~PaddlesManager()
{
}

void PaddlesManager::Initialise(int optionSelected)
{
  m_active = true;

  m_playerOneScore = 0;
  m_playerTwoScore = 0;

  m_optionSelected = optionSelected;

  m_leftRect = sf::FloatRect(0, 0, 10, Game::instance.GetWindow().getSize().y);
  m_rightRect = sf::FloatRect(Game::instance.GetWindow().getSize().x, 0, 10, Game::instance.GetWindow().getSize().y);

  m_pBall = new Ball;
  Game::instance.m_objects.AddObject(m_pBall);
  m_pBall->Initialise();

  m_pPaddleOne = new Paddle;
  Game::instance.m_objects.AddObject(m_pPaddleOne);
  m_pPaddleOne->Initialise(0, m_pBall);

  if (m_optionSelected == 1)
  {
    m_pPaddleTwo = new Paddle;
    Game::instance.m_objects.AddObject(m_pPaddleTwo);
    m_pPaddleTwo->Initialise(1, m_pBall);
  }
  else
  {
    m_pPaddleTwo = new Paddle;
    Game::instance.m_objects.AddObject(m_pPaddleTwo);
    m_pPaddleTwo->Initialise(3, m_pBall);
  }
}

void PaddlesManager::Update(float deltaTime)
{
  if (m_pBall->GetRect().intersects(m_leftRect))
  {
    m_playerTwoScore++;
    m_pBall->Initialise();
    m_pPaddleOne->Initialise(0, m_pBall);
   
    if (m_optionSelected == 1)
    {
      m_pPaddleTwo->Initialise(1, m_pBall);
    }
    else
    {
      m_pPaddleTwo->Initialise(3, m_pBall);
    }
  }
  else if (m_pBall->GetRect().intersects(m_rightRect))
  {
    m_playerOneScore++;
    m_pBall->Initialise();

    m_pPaddleOne->Initialise(0, m_pBall);

    if (m_optionSelected == 1)
    {
      m_pPaddleTwo->Initialise(1, m_pBall);
    }
    else
    {
      m_pPaddleTwo->Initialise(3, m_pBall);
    }
  }
}

void PaddlesManager::Draw()
{
  DrawManager* pDrawManager = DrawManager::GetInstance();

  pDrawManager->DrawText("" + std::to_string(m_playerOneScore), 40, sf::Vector2f(0, 0));
  pDrawManager->DrawText("" + std::to_string(m_playerTwoScore), 40, sf::Vector2f(Game::instance.GetWindow().getSize().x-10, 0), sf::Color::White, alignment::TOPRIGHT);
}