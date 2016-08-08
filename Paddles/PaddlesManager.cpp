#include "PaddlesManager.h"
#include "Game.h"
#include "DrawManager.h"
#include "InputManager.h"
#include <string>

PaddlesManager::PaddlesManager()
{
  m_outBuffer.loadFromFile("sound/out.wav");
}

PaddlesManager::~PaddlesManager()
{
}

void PaddlesManager::Initialise(int optionSelected)
{
  m_active = true;

  m_gameOver = false;

  m_playerOneScore = 0;
  m_playerTwoScore = 0;

  m_optionSelected = optionSelected;

  m_leftRect = sf::FloatRect(0, 0, 10, Game::instance.GetWindow().getSize().y);
  m_rightRect = sf::FloatRect(Game::instance.GetWindow().getSize().x, 0, 10, Game::instance.GetWindow().getSize().y);

  m_outSound.setBuffer(m_outBuffer);

  if (m_optionSelected == 1)
  {
    m_pBall = new Ball;
    Game::instance.m_objects.AddObject(m_pBall);
    m_pBall->Initialise(true);

    m_pPaddleTwo = new Paddle;
    Game::instance.m_objects.AddObject(m_pPaddleTwo);
    m_pPaddleTwo->Initialise(1, m_pBall);
  }
  else
  {
    m_pBall = new Ball;
    Game::instance.m_objects.AddObject(m_pBall);
    m_pBall->Initialise(false);

    m_pPaddleTwo = new Paddle;
    Game::instance.m_objects.AddObject(m_pPaddleTwo);
    m_pPaddleTwo->Initialise(3, m_pBall);
  }

  m_pPaddleOne = new Paddle;
  Game::instance.m_objects.AddObject(m_pPaddleOne);
  m_pPaddleOne->Initialise(0, m_pBall);
}

void PaddlesManager::Update(float deltaTime)
{
  InputManager* pInputManager = InputManager::GetInstance();

  if (m_pBall->GetRect().intersects(m_leftRect))
  {
    m_playerTwoScore++;

    if (m_optionSelected == 1)
    {
      m_pBall->Initialise(true);
      m_pPaddleTwo->Initialise(1, m_pBall);
    }
    else
    {
      m_pBall->Initialise(false);
      m_pPaddleTwo->Initialise(3, m_pBall);
    }

    m_pPaddleOne->Initialise(0, m_pBall);

    m_outSound.play();
  }
  else if (m_pBall->GetRect().intersects(m_rightRect))
  {
    m_playerOneScore++;

    if (m_optionSelected == 1)
    {
      m_pBall->Initialise(true);
      m_pPaddleTwo->Initialise(1, m_pBall);

    }
    else
    {
      m_pBall->Initialise(false);
      m_pPaddleTwo->Initialise(3, m_pBall);

    }

    m_pPaddleOne->Initialise(0, m_pBall);

    m_outSound.play();
  }

  if (m_playerOneScore >= 5 && !m_gameOver)
  {
    m_pBall->Deactivate();
    m_pPaddleOne->Deactivate();
    m_pPaddleTwo->Deactivate();

    m_gameOver = true;
  }
  else if (m_playerTwoScore >= 5 && !m_gameOver)
  {
    m_pBall->Deactivate();
    m_pPaddleOne->Deactivate();
    m_pPaddleTwo->Deactivate();

    m_gameOver = true;
  }

  if (pInputManager->KeyUp(sf::Keyboard::Escape) && m_gameOver)
  {
    Game::instance.SetState(Game::GameState::ShowingMenu);
    m_active = false;
  }

  if (pInputManager->KeyUp(sf::Keyboard::Return) && m_gameOver)
  {
    Initialise(m_optionSelected);
  }
}

void PaddlesManager::Draw()
{
  DrawManager* pDrawManager = DrawManager::GetInstance();

  pDrawManager->BasicRect(sf::FloatRect((Game::instance.GetWindow().getSize().x / 2)-2.5, 0, 5, Game::instance.GetWindow().getSize().y), sf::Color(200, 200, 200));

  pDrawManager->DrawText(std::to_string(m_playerOneScore), 70, sf::Vector2f(20, 0));
  pDrawManager->DrawText(std::to_string(m_playerTwoScore), 70, sf::Vector2f(Game::instance.GetWindow().getSize().x-20, 0), sf::Color::White, alignment::TOPRIGHT);

  if (m_playerOneScore + m_playerTwoScore == 0)
  {
    pDrawManager->DrawText("W", 100, sf::Vector2f(Game::instance.GetWindow().getSize().x / 4, Game::instance.GetWindow().getSize().y / 4), sf::Color(200, 200, 200), alignment::MIDDLECENTER);
    pDrawManager->DrawText("S", 100, sf::Vector2f(Game::instance.GetWindow().getSize().x / 4, (Game::instance.GetWindow().getSize().y / 4) * 3), sf::Color(200, 200, 200), alignment::MIDDLECENTER);

    if (m_optionSelected == 1)
    {
      pDrawManager->DrawText("Up", 100, sf::Vector2f((Game::instance.GetWindow().getSize().x / 4) * 3, Game::instance.GetWindow().getSize().y / 4), sf::Color(200, 200, 200), alignment::MIDDLECENTER);
      pDrawManager->DrawText("Down", 100, sf::Vector2f((Game::instance.GetWindow().getSize().x / 4) * 3, (Game::instance.GetWindow().getSize().y / 4) * 3), sf::Color(200, 200, 200), alignment::MIDDLECENTER);
    }
  }

  if (m_playerOneScore >= 5 && m_gameOver)
  {
    pDrawManager->DrawText("Win", 100, sf::Vector2f((Game::instance.GetWindow().getSize().x / 4), Game::instance.GetWindow().getSize().y / 2), sf::Color(200, 200, 200), alignment::MIDDLECENTER);

    pDrawManager->DrawText("Press esc to exit or \nenter to play again", 30, sf::Vector2f((Game::instance.GetWindow().getSize().x / 4), 
                           Game::instance.GetWindow().getSize().y / 1.2f), sf::Color(200, 200, 200), alignment::MIDDLECENTER);
  }
  else if (m_playerTwoScore >= 5 && m_gameOver)
  {
    pDrawManager->DrawText("Win", 100, sf::Vector2f((Game::instance.GetWindow().getSize().x / 4) * 3, Game::instance.GetWindow().getSize().y / 2), sf::Color(200, 200, 200), alignment::MIDDLECENTER);

    pDrawManager->DrawText("Press esc to exit or \nenter to play again", 30, sf::Vector2f((Game::instance.GetWindow().getSize().x / 4)*3,
      Game::instance.GetWindow().getSize().y / 1.2f), sf::Color(200, 200, 200), alignment::MIDDLECENTER);
  }
}