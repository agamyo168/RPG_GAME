#include "State/GameState.hpp"
#include <iostream>

GameState::GameState(sf::RenderWindow *window) : State(window) {}
GameState::~GameState() {}

void GameState::endState() {}
void GameState::update(const float &dt) {
  std::cout << "GameState render" << std::endl;
}
void GameState::render(sf::RenderTarget *target) {}