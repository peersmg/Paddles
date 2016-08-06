#pragma once
#include "GameObject.h"
#include "DrawManager.h"

class Ball : public GameObject
{
private:
  sf::Vector2f m_velocity;

public:
  Ball();
  ~Ball();

  void Initialise();
  void Update(float deltaTime);
  void Draw();

  sf::Vector2f GetPosition();
};