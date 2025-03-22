#include "State/State.hpp"
#include <SFML/Window/Keyboard.hpp>

State::State(sf::RenderWindow *window) {
  this->window = window;
  this->quit = false;
}
State::~State() {}
void State::checkForQuit() {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    this->quit = true;
}
void State::setQuit(const bool &value) { this->quit = value; }
const bool &State::getQuit() const { return this->quit; }