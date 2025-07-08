#include "Building.hpp"

Building::Building(float x, float y, float size, BuildingType type): type(type)
{
    shape.setSize(sf::Vector2f(size, size));
    shape.setPosition(x, y);

    switch (type) {
        case BuildingType::House:
            shape.setFillColor(sf::Color::Blue);
            break;
        case BuildingType::SolarPanel:
            shape.setFillColor(sf::Color::Yellow);
            break;
        case BuildingType::WaterTank:
            shape.setFillColor(sf::Color::Cyan);
            break;
    }
}

void Building::draw(sf::RenderWindow &window) const
{
    window.draw(shape);
}

sf::Vector2f Building::getPosition() const
{
    return shape.getPosition();
}

BuildingType Building::getType() const
{
    return type;
}

bool Building::contains(sf::Vector2f point) const
{
    return shape.getGlobalBounds().contains(point);
}