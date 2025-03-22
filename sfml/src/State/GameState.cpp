#include "State/GameState.hpp"
#include <iostream>
#include <ostream>

GameState::GameState(sf::RenderWindow *window) : State(window) {}
GameState::~GameState() {}

void GameState::updateKeybinds(const float &dt) {
  this->checkForQuit();
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    std::cout << "A" << std::endl;
}
void GameState::endState() {
  if (!this->getQuit())
    std::cout << "Game state exited!" << std::endl;
}
void GameState::update(const float &dt) { this->updateKeybinds(dt); }
void GameState::render(sf::RenderTarget *target) {}