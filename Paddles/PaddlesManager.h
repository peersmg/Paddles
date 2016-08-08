#pragma once
#include "GameObject.h"
#include "Ball.h"
#include "Paddle.h"
#include "stdafx.h"

class PaddlesManager : public GameObject
{
private:
  int m_playerOneScore;
  int m_playerTwoScore;
  int m_optionSelected;

  sf::FloatRect m_leftRect;
  sf::FloatRect m_rightRect;
  Ball* m_pBall;
  Paddle* m_pPaddleOne;
  Paddle* m_pPaddleTwo;

public:
  PaddlesManager();
  ~PaddlesManager();

  void Initialise(int players);
  void Update(float deltaTime);
  void Draw();

  void IncrementScore(int optionSelected);
};

