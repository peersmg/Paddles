#pragma once
#include "GameObject.h"
#include "Ball.h"

class Paddle : public GameObject
{
private:
  sf::Vector2f m_velocity;        // Paddle velocity
  int m_player;                   // Paddle one or two
  Ball* m_pBall;                  // Pointer to the ball
  sf::FloatRect m_rect;           // Paddle rect

  sf::SoundBuffer m_hitBuffer;    // Buffer for 'Hit' sound
  sf::Sound m_hitSound;           // 'Hit' sound container

public:
  Paddle();
  ~Paddle();

  // Initalise the paddle
  void Initialise(int player, Ball* pBall);
  
  // Update paddle position
  void Update(float deltaTime);
  
  // Draw the paddle
  void Draw();

  // Deactivate the paddle object
  void Deactivate();

  // Process any collisions
  void ProcessCollision();
};

