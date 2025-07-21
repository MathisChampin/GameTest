#ifndef BUILDINGCOMPONENT_HPP_
    #define BUILDINGCOMPONENT_HPP_

    #include <cstdint>

// Enum pour représenter les différents types de bâtiments
enum class BuildingType {
    House,
    SolarPanel,
    WaterTank,
    Unknown // Pour les bâtiments non définis
};

// Composant qui stocke les infos spécifiques à un bâtiment
struct BuildingComponent {
    BuildingType type = BuildingType::Unknown; // Type du bâtiment

    int electricityProduction = 0; // Production d'électricité
    int electricityConsumption = 0; // Consommation d'électricité
    int waterProduction = 0;       // Production d'eau
    int waterConsumption = 0;      // Consommation d'eau

    // Constructeur pratique
    BuildingComponent(BuildingType type = BuildingType::Unknown) : type(type) {
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
            case BuildingType::Unknown:
                // Pas de production/consommation par défaut
                break;
        }
    }

    // Get pour les valeurs de production/consommation
    int getElectricityConsumption() const {
        return electricityConsumption;
    }

    int getElectricityProduction() const {
        return electricityProduction;
    }

    int getWaterConsumption() const {
        return waterConsumption;
    }

    int getWaterProduction() const {
        return waterProduction;
    }
};

#endif // BUILDINGCOMPONENT_HPP_
