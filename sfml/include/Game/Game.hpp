#ifndef GAME_HPP
#define GAME_HPP
#include "State/State.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include <stack>

class Game {
private:
  // Variables
  sf::RenderWindow *window;
  sf::Event sfEvent;
  sf::Clock dtClock;
  float dt; // keeps track of how long to render and update a frame
  std::stack<State *> states;
  // Initialization
  void initWindow();
  void initStates();

public:
  Game();
  virtual ~Game();
  // Functions
  void run();
  void updateDt();
  void updateSFMLEvents();
  void update();
  void render();
};
#endif