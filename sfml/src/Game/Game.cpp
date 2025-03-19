#include "Game/Game.hpp"
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
Game::Game() { this->initWindow(); }
Game::~Game() { delete this->window; }
void Game::run() {
  while (window->isOpen()) {
    this->updateDt();
    this->update();
    this->render();
  }
}

void clearShellScreen() {
#ifdef _WIN32
  int result = system("cls"); // Windows
#elif linux
  int result = system("clear");
#endif
  if (result != 0) {
    std::cerr << "Failed to clear the screen!" << std::endl;
  }
}
void Game::update() { this->updateSFMLEvents(); }
void Game::updateDt() {
  /* Update dt with the time it takes to update and render a frame*/
  this->dt = this->dtClock.restart().asSeconds();
  clearShellScreen();
  std::cout << this->dt << std::endl;
}
void Game::render() {
  window->clear();
  window->display();
}
void Game::updateSFMLEvents() {
  sf::Event event;
  while (window->pollEvent(event)) {
    if (event.type == sf::Event::Closed)
      window->close();
  }
}