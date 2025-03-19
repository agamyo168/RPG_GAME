#ifndef STATE_HPP
#define STATE_HPP
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Event.hpp>
#include <vector>

class State {
  private:
    std::vector<sf::Texture> textures;

  public:
    State();
    virtual ~State();

    virtual void
    update() = 0; // PURE VIRTUAL FUNCTION -> Makes sure that when you inherit
                  // from State you must overwrite them.
    virtual void render() = 0;
};
#endif