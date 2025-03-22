#ifndef ENTITY_HPP
#define ENTITY_HPP
#include <SFML/Graphics/RectangleShape.hpp>
class Entity {
private:
protected:
  sf::RectangleShape shape;
  float movementSpeed;

public:
  Entity();
  virtual ~Entity();

  // functions
  virtual void render(sf::RenderTarget *target = nullptr);
  virtual void update(const float &dt);
  virtual void move(const float &dt, const float &dirX, const float &dirY);
};
#endif