#include "InputSystem.hpp"

void InputSystem::update(sf::RenderWindow &window)
{
    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape) {
            window.close();
        }

        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                handleLeftClick(mousePos);
            }
            if (event.mouseButton.button == sf::Mouse::Right) {
                handleRightClick();
            }
        }

        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Space) {
                handlePlaceBuilding();
            }
            if (event.key.code == sf::Keyboard::R) {
                handleReset();
            }
            if (event.key.code == sf::Keyboard::A ||
                event.key.code == sf::Keyboard::Z ||
                event.key.code == sf::Keyboard::E) {
                handleTypeSwitch(event.key.code);
            }
        }
    }
}

void InputSystem::handleLeftClick(const sf::Vector2f &mousePos)
{
    bool inside = false;
    for (Entity entity : entities) {
        auto &pos = positions.at(entity);
        auto &selectable = selectables.at(entity);

        inside = (mousePos.x >= pos.x && mousePos.x <= pos.x + pos.width &&
                       mousePos.y >= pos.y && mousePos.y <= pos.y + pos.height);

        selectable.isSelected = inside;
    }
}

void InputSystem::handleRightClick() {
    for (Entity entity : entities) {
        selectables.at(entity).isSelected = false;
    }
}

void InputSystem::handlePlaceBuilding()
{
    placeBuildingRequested = true;
}

void InputSystem::handleReset()
{
    resetRequested = true;
}

void InputSystem::handleTypeSwitch(sf::Keyboard::Key key) 
{
    switch (key) {
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
