#include "Game/Game.hpp"
// #include <cstdlib>
#include <iostream>

// Initialization
void Game::initWindow() {
    this->window = new sf::RenderWindow(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
}
Game::Game() { this->initWindow(); }
Game::~Game() { delete this->window; }
void Game::run() {
    while (window->isOpen()) {
        this->updateDt();
        this->update();
        this->render();
    }
}

void clearShellScreen() {
#ifdef _WIN32
    int result = system("cls"); // Windows
#elif linux
    int result = system("clear");
#endif
    if (result != 0) {
        std::cerr << "Failed to clear the screen!" << std::endl;
    }
}
void Game::update() { this->updateSFMLEvents(); }
void Game::updateDt() {
    /* Update dt with the time it takes to update and render a frame*/
    this->dt = this->dtClock.restart().asSeconds();
    clearShellScreen();
    std::cout << this->dt << std::endl;
}
void Game::render() {
    window->clear();
    window->display();
}
void Game::updateSFMLEvents() {
    sf::Event event;
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window->close();
    }
}