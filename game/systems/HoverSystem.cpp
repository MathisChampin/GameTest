#include "HoverSystem.hpp"

void HoverSystem::update(const sf::Vector2f &mousePos)
{
    bool inside = false;

    for (Entity entity : entities) {
        const auto &pos = positions.at(entity);
        auto &selectable = selectables.at(entity);

        inside = (mousePos.x >= pos.x && mousePos.x <= pos.x + pos.width &&
                       mousePos.y >= pos.y && mousePos.y <= pos.y + pos.height);

        selectable.isHovered = inside;
    }
}
