#pragma once
#include "GameObject.h"
#include "Ball.h"

class Paddle : public GameObject
{
private:
  sf::Vector2f m_velocity;
  int m_player;
  Ball* m_pBall;

public:
  Paddle();
  ~Paddle();

  void Initialise(int player, Ball* pBall);
  void Update(float deltaTime);
  void Draw();

  void ProcessCollision();
};

