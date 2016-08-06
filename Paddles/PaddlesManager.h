#pragma once
#include "GameObject.h"
class PaddlesManager : public GameObject
{
private:
  int m_playerOneScore;
  int m_playerTwoScore;

public:
  PaddlesManager();
  ~PaddlesManager();

  void Initialise(int players);
  void Update(float deltaTime);
  void Draw();

  void IncrementScore(int optionSelected);
};

