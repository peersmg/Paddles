#pragma once
#include "GameObject.h"
#include "DrawManager.h"

class Ball : public GameObject
{
private:
  sf::Vector2f m_velocity;
  sf::FloatRect m_rect;

  bool m_twoPlayer;

public:
  Ball();
  ~Ball();

  void Initialise(bool twoPlayer);
  void Update(float deltaTime);
  void Draw();

  void Deactivate();

  sf::FloatRect GetRect();
  sf::Vector2f GetPosition();
  sf::Vector2f GetVelocity();
  void SetVelocity(sf::Vector2f newVelocity);
};