#include "Game.hpp"

Game::Game(): window(sf::VideoMode(1920, 1080), "Green City"), tileMap(10, 10, 64.f)
{
    window.setFramerateLimit(60);
}

Game::~Game() {}

void Game::run()
{
    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void Game::processEvents()
{
    sf::Event event;

    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            window.close();
    }
}

void Game::update()
{
    sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
    sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);

    tileMap.updateHover(worldPos);
}

void Game::render()
{
    window.clear(sf::Color::Black);
    tileMap.draw(window);
    window.display();
}