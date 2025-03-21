#ifndef STATE_HPP
#define STATE_HPP
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Event.hpp>
#include <vector>

class State {
private:
  std::vector<sf::Texture> textures;
  sf::RenderWindow *window;

public:
  State(sf::RenderWindow *window);
  virtual ~State();
  virtual void endState() = 0;
  virtual void update(
      const float &dt) = 0; // PURE VIRTUAL FUNCTION -> Makes sure that when
                            // you inherit from State you must overwrite them.
  virtual void render(sf::RenderTarget *target = nullptr) = 0;
};
#endif