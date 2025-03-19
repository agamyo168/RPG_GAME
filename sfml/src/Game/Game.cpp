#include "Game/Game.hpp"
// Initialization
void Game::initWindow() {
  this->window = new sf::RenderWindow(sf::VideoMode(200, 200), "SFML works!");
  sf::CircleShape shape(100.f);
}
Game::Game() { this->initWindow(); }
Game::~Game() { delete this->window; }
void Game::run() {
  while (window->isOpen()) {
    this->update();
    this->render();
  }
}
void Game::update() { this->updateSFMLEvents(); }
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