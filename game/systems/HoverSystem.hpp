#ifndef HOVERSYSTEM_HPP_
    #define HOVERSYSTEM_HPP_

    #include "../../engine/ecs/SystemManager.hpp"
    #include "../components/PositionComponent.hpp"
    #include "../components/SelectableComponent.hpp"

    #include <SFML/Graphics.hpp>
    #include <unordered_map>

class HoverSystem : public ISystem {
    public:

        // Constructeur
        HoverSystem(
            const std::unordered_map<Entity, PositionComponent> &positions,
            std::unordered_map<Entity, SelectableComponent> &selectables
        ): positions(positions), selectables(selectables) {}

        // Met à jour l'état de survol des entités en fonction de la position de la souris
        void update(const sf::Vector2f  &mousePos);

    private:
        const std::unordered_map<Entity, PositionComponent> &positions;
        std::unordered_map<Entity, SelectableComponent> &selectables;
};

#endif // HOVERSYSTEM_HPP_
