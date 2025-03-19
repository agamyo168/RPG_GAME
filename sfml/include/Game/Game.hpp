#ifndef GAME_HPP
#define GAME_HPP
#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>

class Game {
private:
  // Variables
  sf::RenderWindow *window;
  sf::Event sfEvent;
  sf::Clock dtClock;
  float dt; // keeps track of how long to render and update a frame
  // Initialization
  void initWindow();

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