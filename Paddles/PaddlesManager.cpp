#include "PaddlesManager.h"
#include "Ball.h"
#include "Game.h"
#include "Paddle.h"
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

  Ball* pBall = new Ball;
  Game::instance.m_objects.AddObject(pBall);
  pBall->Initialise();

  Paddle* pPaddleOne = new Paddle;
  Game::instance.m_objects.AddObject(pPaddleOne);
  pPaddleOne->Initialise(0, pBall);

  if (optionSelected == 1)
  {
    Paddle* pPaddleTwo = new Paddle;
    Game::instance.m_objects.AddObject(pPaddleTwo);
    pPaddleTwo->Initialise(1, pBall);
  }
  else
  {
    Paddle* pPaddleTwo = new Paddle;
    Game::instance.m_objects.AddObject(pPaddleTwo);
    pPaddleTwo->Initialise(3, pBall);
  }
}

void PaddlesManager::Update(float deltaTime)
{

}

void PaddlesManager::Draw()
{
  DrawManager* pDrawManager = DrawManager::GetInstance();

  pDrawManager->DrawText("" + std::to_string(m_playerOneScore), 40, sf::Vector2f(0, 0));
  pDrawManager->DrawText("" + std::to_string(m_playerTwoScore), 40, sf::Vector2f(Game::instance.GetWindow().getSize().x-10, 0), sf::Color::White, alignment::TOPRIGHT);
}