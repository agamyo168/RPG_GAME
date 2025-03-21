#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP
#include "State/State.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Event.hpp>

class GameState : public State {
private:
public:
  GameState(sf::RenderWindow *window);
  virtual ~GameState();

  void endState();
  void update(const float &dt);
  void render(sf::RenderTarget *target = nullptr);
};
#endif