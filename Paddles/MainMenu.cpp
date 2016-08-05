#include "MainMenu.h"
#include "DrawManager.h"
#include "stdafx.h"
#include "Game.h"
#include "InputManager.h"

MainMenu::MainMenu()
{
}


MainMenu::~MainMenu()
{
}

void MainMenu::Initialise()
{
  m_active = true;
  m_optionSelected = 0;
}

void MainMenu::Update(float deltaTime)
{
  InputManager* pInputManager = InputManager::GetInstance();

  if (pInputManager->KeyDown(sf::Keyboard::Up))
  {
    m_optionSelected = 0;
  }
  else if (pInputManager->KeyDown(sf::Keyboard::Down))
  {
    m_optionSelected = 1;
  }
}

void MainMenu::Draw()
{
  DrawManager* pDrawManager = DrawManager::GetInstance();

  // Title
  pDrawManager->DrawText("Paddles", 70, sf::Vector2f(Game::instance.GetWindow().getSize().x/2, 50));

  // Option One
  pDrawManager->DrawText("1 Player", 40, sf::Vector2f(Game::instance.GetWindow().getSize().x / 2, 360));

  // Option Two
  pDrawManager->DrawText("2 Player", 40, sf::Vector2f(Game::instance.GetWindow().getSize().x / 2, 520));

  if (m_optionSelected == 0)
  {
    pDrawManager->BasicRect(rect(Game::instance.GetWindow().getSize().x / 2, 360, 10, 10), sf::Color::White);
  }
  else
  {

  }
}