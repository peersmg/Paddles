#include "MainMenu.h"
#include "DrawManager.h"
#include "stdafx.h"
#include "Game.h"
#include "InputManager.h"
#include "PaddlesManager.h"

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

  if (pInputManager->KeyDown(sf::Keyboard::Return))
  {
    Game::instance.SetState(Game::GameState::Playing);

    PaddlesManager* pPaddleManager = new PaddlesManager;
    Game::instance.m_objects.AddObject(pPaddleManager);
    pPaddleManager->Initialise(m_optionSelected);

    m_active = false;
  }
  else if (pInputManager->KeyDown(sf::Keyboard::Up))
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

  static sf::FloatRect playerOneRect = sf::FloatRect(0,0,0,0);
  static sf::FloatRect playerTwoRect = sf::FloatRect(0, 0, 0, 0);

  if (m_optionSelected == 0)
  {
    pDrawManager->BasicRect(sf::FloatRect(0, playerOneRect.top-10, Game::instance.GetWindow().getSize().x, playerOneRect.height+20), sf::Color::White);

    // Option One
    playerOneRect = pDrawManager->DrawText("1 Player", 40, sf::Vector2f(Game::instance.GetWindow().getSize().x / 2, 360), sf::Color::Black, alignment::TOPCENTER);

    // Option Two
    playerTwoRect = pDrawManager->DrawText("2 Player", 40, sf::Vector2f(Game::instance.GetWindow().getSize().x / 2, 520), sf::Color::White, alignment::TOPCENTER);
  }
  else
  {
    pDrawManager->BasicRect(sf::FloatRect(0, playerTwoRect.top-10, Game::instance.GetWindow().getSize().x, playerTwoRect.height+20), sf::Color::White);

    // Option One
    playerOneRect = pDrawManager->DrawText("1 Player", 40, sf::Vector2f(Game::instance.GetWindow().getSize().x / 2, 360), sf::Color::White, alignment::TOPCENTER);

    // Option Two
    playerTwoRect = pDrawManager->DrawText("2 Player", 40, sf::Vector2f(Game::instance.GetWindow().getSize().x / 2, 520), sf::Color::Black, alignment::TOPCENTER);
  }

  // Title
  pDrawManager->DrawText("Paddles", 70, sf::Vector2f(Game::instance.GetWindow().getSize().x / 2, 50), sf::Color::White, alignment::TOPCENTER);
}