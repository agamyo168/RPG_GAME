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
protected:
  std::vector<sf::Texture> textures;
  sf::RenderWindow *window;
  bool quit;

public:
  State(sf::RenderWindow *window);
  virtual ~State();
  const bool &getQuit() const;
  void checkForQuit();
  void setQuit(const bool &value);

  virtual void endState() = 0;

  ////////////////////////////////////////////////////////////
  /// \brief Checks for keyboard strokes.
  ///
  ////////////////////////////////////////////////////////////
  virtual void updateKeybinds(const float &dt) = 0;
  virtual void update(const float &dt) = 0;
  virtual void render(sf::RenderTarget *target = nullptr) = 0;
};
#endif