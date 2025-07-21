#ifndef INPUTSYSTEM_HPP_
#define INPUTSYSTEM_HPP_

#include "../../engine/ecs/SystemManager.hpp"
#include "../components/PositionComponent.hpp"
#include "../components/SelectableComponent.hpp"
#include "../components/BuildingComponent.hpp"

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <functional>

class InputSystem : public ISystem {
    public:

        // Constructeur qui prend les références aux composants nécessaires
        InputSystem(
            std::unordered_map<Entity, PositionComponent> &positions,
            std::unordered_map<Entity, SelectableComponent> &selectables
        ): positions(positions), selectables(selectables) {}

        // Met à jour l'état du système en fonction des événements de la fenêtre
        void update(sf::RenderWindow &window);

        // Gère les clics de souris et les touches pressées
        void handleLeftClick(const sf::Vector2f &mousePos);
        void handleRightClick();
        void handlePlaceBuilding();
        void handleReset();
        void handleTypeSwitch(sf::Keyboard::Key key);

        // Vérifie si une entité ...
        BuildingType getCurrentBuildingType() const { 
            return currentBuildingType;
        }

        bool shouldPlaceBuilding() const {
            return placeBuildingRequested;
        }

        bool shouldReset() const {
            return resetRequested;
        }

    private:
        std::unordered_map<Entity, PositionComponent> &positions;
        std::unordered_map<Entity, SelectableComponent> &selectables;

        BuildingType currentBuildingType = BuildingType::Unknown;
        bool placeBuildingRequested = false;
        bool resetRequested = false;
};

#endif // INPUTSYSTEM_HPP_
