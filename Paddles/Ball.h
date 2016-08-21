#pragma once
#include "GameObject.h"
#include "DrawManager.h"

class Ball : public GameObject
{
private:
  sf::Vector2f m_velocity;    // Velocity of the ball
  sf::FloatRect m_rect;       // Ball rect

  bool m_twoPlayer;           // Is the game single player or two player

public:
  Ball();
  ~Ball();

  // Initialise the ball
  void Initialise(bool twoPlayer);

  // Update the ball position
  void Update(float deltaTime);

  // Draw the ball
  void Draw();

  // Deactivate the ball
  void Deactivate();

  // Return the ball rect
  sf::FloatRect GetRect();

  // Return the ball position
  sf::Vector2f GetPosition();

  // Return the ball velocity
  sf::Vector2f GetVelocity();

  // Set the ball velocity
  void SetVelocity(sf::Vector2f newVelocity);
};