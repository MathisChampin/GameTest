#include "RenderSystem.hpp"

void RenderSystem::update(sf::RenderWindow &window)
{
    for (Entity entity : entities) {
        const auto &rect = buildRectangle(entity);
        window.draw(rect);
    }
}

sf::RectangleShape RenderSystem::buildRectangle(Entity entity) const
{
    const auto &pos = positions.at(entity);
    const auto &building = buildings.at(entity);
    const auto &selectable = selectables.at(entity);

    sf::RectangleShape rect;
    rect.setSize(sf::Vector2f(pos.width, pos.height));
    rect.setPosition(pos.x, pos.y);
    rect.setFillColor(getColor(building, selectable));

    return rect;
}

sf::Color RenderSystem::getColor(const BuildingComponent &building, const SelectableComponent &selectable) const
{
    if (selectable.isSelected) return sf::Color::Red;
    if (selectable.isHovered) return sf::Color::Green;

    switch (building.type) {
        case BuildingType::House: return sf::Color::Blue;
        case BuildingType::SolarPanel: return sf::Color::Yellow;
        case BuildingType::WaterTank: return sf::Color::Cyan;
        default: return sf::Color::White;
    }
}
