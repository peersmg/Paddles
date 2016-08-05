#include "Game.h"
#include "InputManager.h"
#include "DrawManager.h"
#include "MainMenu.h"

void Game::Start()
{
  if (_gameState != GameState::Uninitialized)
  {
    return;
  }

  std::cout << "Message: Starting..." << std::endl;

  _mainWindow.create(sf::VideoMode(1024, 768, 32), "Pang", sf::Style::Titlebar | sf::Style::Close);
  _gameState = GameState::ShowingSplash;

  //Initialise DrawManager
  DrawManager::GetInstance()->Initialise();

  //Start code here
  SplashScreen *mainSplash = new SplashScreen;
  m_objects.AddObject(mainSplash);
  mainSplash->Initialise();
  //

  while (!IsExiting())
  {
    GameLoop();
  }

  std::cout << "Message: Exiting...\n";

  _mainWindow.close();
}

sf::RenderWindow &Game::GetWindow()
{
  return _mainWindow;
}

bool Game::IsExiting()
{
  if (_gameState == GameState::Exiting)
  {
    return true;
  }
  else
  {
    return false;
  }
}

void Game::GameLoop()
{

  if (!IsExiting())
  {
    // Clear to black
    _mainWindow.clear(sf::Color(0, 0, 0));

    //// GAME STUFF HERE ////

    if (_prevGameState != _gameState)
    {
      switch (Game::_gameState)
      {
      case Game::GameState::Uninitialized:

        _prevGameState = GameState::Uninitialized;
        break;
      case Game::GameState::ShowingSplash:
        _prevGameState = GameState::ShowingSplash;
        break;
      case Game::GameState::Paused:
        std::cout << "Message: Paused\n";
        _prevGameState = GameState::Paused;
        break;
      case Game::GameState::ShowingMenu:
      {
        std::cout << "Message: Adding menu class\n";

        MainMenu* menu = new MainMenu;
        m_objects.AddObject(menu);
        menu->Initialise();

        _prevGameState = GameState::ShowingMenu;
      }
        break;
      case Game::GameState::Playing:
        std::cout << "Message: Playing\n";
        _prevGameState = GameState::Playing;
        break;
      case Game::GameState::Exiting:

        _prevGameState = GameState::Exiting;
        break;
      default:
        break;
      }
    }

    ////

    // Update the inputs
    InputManager::GetInstance()->Update();

    // Draw and update GameObjects here

    m_objects.UpdateAll();
    m_objects.DrawAll();

    m_objects.DeleteInactiveObjects();

    //

    _mainWindow.display();
  }
}

void Game::SetState(GameState newState)
{
  _gameState = newState;
}



Game Game::instance;