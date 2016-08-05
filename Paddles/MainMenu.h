#pragma once
#include "GameObject.h"
class MainMenu : public GameObject
{
private:
  int m_optionSelected;

public:
  MainMenu();
  ~MainMenu();

  void Initialise();
  void Update(float deltaTime);
  void Draw();
};

