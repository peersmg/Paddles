#pragma once
#include "GameObject.h"
#include "Ball.h"
#include "Paddle.h"
#include "stdafx.h"

class PaddlesManager : public GameObject
{
private:
  int m_playerOneScore;         // First player score
  int m_playerTwoScore;         // Second player score
  int m_optionSelected;         // The menu option selected

  bool m_gameOver;              // Has one player reached a score of 5

  sf::FloatRect m_leftRect;     // Collider box on left side of screen
  sf::FloatRect m_rightRect;    // Collider box on right side of screen
  Ball* m_pBall;                // Pointer to the ball
  Paddle* m_pPaddleOne;         // First player paddle
  Paddle* m_pPaddleTwo;         // Second player paddle

  sf::SoundBuffer m_outBuffer;  // Buffer for 'out' sound
  sf::Sound m_outSound;         // 'out' sound container

public:
  PaddlesManager();
  ~PaddlesManager();

  // Initialise the paddle manager
  void Initialise(int players);
  
  // Check if the ball has entered either of the colliders
  void Update(float deltaTime);
  
  // Draw the user interface
  void Draw();
};

