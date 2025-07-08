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
        if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
            window.close();
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2f worldPos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
            tileMap.handleClick(worldPos);
        }
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::B) {
            sf::Vector2f worldPos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
            tileMap.placeBuilding(worldPos);
        }
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