#include "Building.hpp"

Building::Building(float x, float y, float size, sf::Color color)
{
    shape.setSize(sf::Vector2f(size, size));
    shape.setPosition(x, y);
    shape.setFillColor(color);
}

void Building::draw(sf::RenderWindow &window) const
{
    window.draw(shape);
}

sf::Vector2f Building::getPosition() const
{
    return shape.getPosition();
}
