#include "Game/Game.hpp"
#include "State/GameState.hpp"
#include "Utils/ShellHandler.hpp"
// #include <cstdlib>
#include <SFML/Window/ContextSettings.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <cstdint>
#include <iostream>

// Initialization
void Game::initWindow() {
  // Defaults
  std::string title = "None";
  sf::VideoMode window_bounds(800, 600);
  uint32_t framerate_limit = 120;
  bool vertical_sync_enabled = false;

  // Read window init
  std::string windowInitFilePath = "Config/window.ini";
  // TODO: #Parsing -> Parse Window Init here
  // window.ini parsed
  this->window = new sf::RenderWindow(window_bounds, title);
  this->window->setFramerateLimit(framerate_limit);
  this->window->setVerticalSyncEnabled(vertical_sync_enabled);
}
void Game::initStates() {
  // GameState
  this->states.push(new GameState(this->window));
}
Game::Game() {
  this->initWindow();
  this->initStates();
}
Game::~Game() {
  delete this->window;
  while (!this->states.empty()) {
    delete this->states.top();
    this->states.pop();
  }
}
// Game Loop
void Game::run() {
  while (window->isOpen()) {
    this->updateDt();
    this->update();
    this->render();
  }
}

void Game::update() {
  this->updateSFMLEvents();
  if (!this->states.empty()) {
    this->states.top()->update(this->dt);
    if (this->states.top()->getQuit()) {
      this->states.top()->endState();
      delete this->states.top();
      this->states.pop();
    }

  } else {
    endApplication();
  }
}
void Game::endApplication() { this->window->close(); }
void Game::updateDt() {
  /* Update dt with the time it takes to update and render a frame*/
  this->dt = this->dtClock.restart().asSeconds();
  clearShellScreen();
  std::cout << this->dt << std::endl;
}
void Game::render() {
  window->clear();
  if (!this->states.empty())
    this->states.top()->render(this->window);
  window->display();
}
void Game::updateSFMLEvents() {
  sf::Event event;
  while (window->pollEvent(event)) {
    if (event.type == sf::Event::Closed)
      window->close();
  }
}