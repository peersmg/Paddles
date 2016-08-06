#include "PaddlesManager.h"
#include "Ball.h"
#include "Game.h"
#include "Paddle.h"

PaddlesManager::PaddlesManager()
{
}


PaddlesManager::~PaddlesManager()
{
}

void PaddlesManager::Initialise(int optionSelected)
{
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

}