#ifndef BUILDINGCOMPONENT_HPP_
    #define BUILDINGCOMPONENT_HPP_

    #include <cstdint>

// Enum pour représenter les différents types de bâtiments
enum class BuildingType {
    House,
    SolarPanel,
    WaterTank
};

// Composant qui stocke les infos spécifiques à un bâtiment
struct BuildingComponent {
    BuildingType type = BuildingType::House; // Type du bâtiment

    int electricityProduction = 0; // Production d'électricité
    int electricityConsumption = 0; // Consommation d'électricité
    int waterProduction = 0;       // Production d'eau
    int waterConsumption = 0;      // Consommation d'eau

    // Constructeur pratique
    BuildingComponent(BuildingType type = BuildingType::House) : type(type) {
        switch (type) {
            case BuildingType::House:
                electricityConsumption = 1;
                break;
            case BuildingType::SolarPanel:
                electricityProduction = 2;
                break;
            case BuildingType::WaterTank:
                waterProduction = 1;
                break;
        }
    }
};

#endif // BUILDINGCOMPONENT_HPP_
