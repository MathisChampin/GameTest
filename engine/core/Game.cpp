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

void Game::processEvents() {
    sf::Event event;

    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed || isEscapePressed(event))
            window.close();
        if (isLeftClick(event))
            handleTileSelection();
        if (isPlaceBuilding(event))
            handleBuildingPlacement();
        if (isChangeTypeKey(event))
            handleTypeSwitch(event);
        if (isRightClick(event))
            handleBuildingDeletion();
    }
}

bool Game::isEscapePressed(const sf::Event &event) const 
{
    return event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape;
}

bool Game::isLeftClick(const sf::Event &event) const 
{
    return event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left;
}

bool Game::isPlaceBuilding(const sf::Event &event) const 
{
    return event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::B;
}

bool Game::isChangeTypeKey(const sf::Event &event) const 
{
    return event.type == sf::Event::KeyPressed &&
           (event.key.code == sf::Keyboard::A ||
            event.key.code == sf::Keyboard::Z ||
            event.key.code == sf::Keyboard::E);
}

void Game::handleTileSelection() 
{
    sf::Vector2f worldPos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
    tileMap.handleClick(worldPos);
}

void Game::handleBuildingPlacement() 
{
    sf::Vector2f worldPos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
    tileMap.placeBuilding(worldPos, currentBuildingType);
}

void Game::handleTypeSwitch(const sf::Event& event)
{
    switch (event.key.code) {
        case sf::Keyboard::A:
            currentBuildingType = BuildingType::House;
            break;
        case sf::Keyboard::Z:
            currentBuildingType = BuildingType::SolarPanel;
            break;
        case sf::Keyboard::E:
            currentBuildingType = BuildingType::WaterTank;
            break;
        default:
            break;
    }
}

bool Game::isRightClick(const sf::Event& event) const
{
    return event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Right;
}

void Game::handleBuildingDeletion()
{
    sf::Vector2f worldPos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
    tileMap.removeBuilding(worldPos);
}

void Game::updateHoverTile()
{
    sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
    sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);
    tileMap.updateHover(worldPos);
}

void Game::updateResources()
{
    resourceManager.reset();

    for (const auto &building : tileMap.getBuildings()) {
        resourceManager.addElectricity(building.getElectricityProduction());
        resourceManager.consumeElectricity(building.getElectricityConsumption());
        resourceManager.addWater(building.getWaterProduction());
        resourceManager.consumeWater(building.getWaterConsumption());
    }
}

void Game::update()
{
    updateHoverTile();
    updateResources();
}

void Game::render()
{
    window.clear(sf::Color::Black);
    tileMap.draw(window);
    window.display();
}