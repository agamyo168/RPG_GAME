#ifndef GAME_HPP
#define GAME_HPP
#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>

class Game {
private:
  // Variables
  sf::RenderWindow *window;
  sf::Event sfEvent;
  // Initialization
  void initWindow();

public:
  Game();
  virtual ~Game();
  // Functions
  void run();
  void update();
  void render();
  void updateSFMLEvents();
};
#endif