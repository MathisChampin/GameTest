#include "Tile.hpp"

Tile::Tile(float x, float y, float size)
{
    shape.setSize(sf::Vector2f(size, size));
    shape.setPosition(x, y);
    shape.setFillColor(sf::Color::White);
    shape.setOutlineColor(sf::Color::Black);
    shape.setOutlineThickness(1.0f);
}

void Tile::draw(sf::RenderWindow& window)
{
    window.draw(shape);
}

void Tile::setColor(sf::Color color)
{
    shape.setFillColor(color);
}

sf::Vector2f Tile::getPosition() const
{
    return shape.getPosition();
}

bool Tile::contains(sf::Vector2f point) const
{
    return shape.getGlobalBounds().contains(point);
}

void Tile::resetColor()
{
    shape.setFillColor(defaultColor);
}

bool Tile::isSelected() const
{
    return shape.getFillColor() == sf::Color::Red;
}

void Tile::select()
{
    shape.setFillColor(sf::Color::Red);
}

void Tile::reset()
{
    shape.setFillColor(defaultColor);
}