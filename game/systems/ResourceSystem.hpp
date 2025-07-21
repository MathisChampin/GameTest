#ifndef RESOURCESYSTEM_HPP_
    #define RESOURCESYSTEM_HPP_

    #include "../../engine/ecs/SystemManager.hpp"
    #include "../components/BuildingComponent.hpp"

    #include <unordered_map>

class ResourceSystem : public ISystem {
    public:

        // Constructeur
        ResourceSystem(const std::unordered_map<Entity, BuildingComponent> &buildings)
            : buildings(buildings), electricity(0), water(0) {}

        // Met à jour les ressources en fonction des bâtiments actifs
        void update();

        // Ajoute de l'électricité
        int getElectricity() const {
            return electricity;
        }
    
        // Ajoute de l'eau
        int getWater() const {
            return water;
        }

private:
    const std::unordered_map<Entity, BuildingComponent> &buildings;
    int electricity;
    int water;
};

#endif // RESOURCESYSTEM_HPP_
