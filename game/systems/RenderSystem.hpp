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
        // Initialise les références aux composants
        void init(
            const std::unordered_map<Entity, PositionComponent>& positions,
            const std::unordered_map<Entity, BuildingComponent>& buildings,
            const std::unordered_map<Entity, SelectableComponent>& selectables
    )   ;

        // Met à jour le rendu : dessine les entités
        void update(sf::RenderWindow& window);
        
        // Fonction utilitaire pour construire un rectangle à partir des composants
        sf::RectangleShape buildRectangle(Entity entity) const;

        //Fonction utilitaire pour obtenir la couleur d'un bâtiment en fonction de son état sélectionné ou survolé
        sf::Color getColor(const BuildingComponent& building, const SelectableComponent& selectable) const;

    private:
        const std::unordered_map<Entity, PositionComponent>* positions;
        const std::unordered_map<Entity, BuildingComponent>* buildings;
        const std::unordered_map<Entity, SelectableComponent>* selectables;

};

#endif // RENDERSYSTEM_HPP_
