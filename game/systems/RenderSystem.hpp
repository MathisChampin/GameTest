#ifndef RENDERSYSTEM_HPP_
    #define RENDERSYSTEM_HPP_

    #include "../../engine/ecs/SystemManager.hpp"
    #include "../components/PositionComponent.hpp"
    #include "../components/BuildingComponent.hpp"
    #include "../components/SelectableComponent.hpp"

    #include <SFML/Graphics.hpp>
    #include <unordered_map>

// Système qui dessine toutes les entités avec Position + Building + Selectable
class RenderSystem : public ISystem {
    public:

        // Constructeur par défaut
        RenderSystem(
            const std::unordered_map<Entity, PositionComponent> &positions,
            const std::unordered_map<Entity, BuildingComponent> &buildings,
            const std::unordered_map<Entity, SelectableComponent> &selectables
        ): positions(positions), buildings(buildings), selectables(selectables) {}

        // Initialise le système avec les références aux composants
        void update(sf::RenderWindow& window);

        // Fonction utilitaire pour construire un rectangle à partir des composants
        sf::RectangleShape buildRectangle(Entity entity) const;
    
        // Récupère la couleur à utiliser pour dessiner un bâtiment en fonction de son état
        sf::Color getColor(const BuildingComponent& building, const SelectableComponent& selectable) const;

private:
    const std::unordered_map<Entity, PositionComponent> &positions;
    const std::unordered_map<Entity, BuildingComponent> &buildings;
    const std::unordered_map<Entity, SelectableComponent> &selectables;
};


#endif // RENDERSYSTEM_HPP_
