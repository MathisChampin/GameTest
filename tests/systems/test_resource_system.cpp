#include <criterion/criterion.h>
#include "../../game/systems/ResourceSystem.hpp"

Test(ResourceSystem, CalculatesResourcesCorrectly) {
    std::unordered_map<Entity, BuildingComponent> buildings = {
        {1, BuildingComponent(BuildingType::House)},        // -1 electricity
        {2, BuildingComponent(BuildingType::SolarPanel)},  // +2 electricity
        {3, BuildingComponent(BuildingType::WaterTank)}    // +1 water
    };

    ResourceSystem rs(buildings);
    rs.entities.insert(1);
    rs.entities.insert(2);
    rs.entities.insert(3);

    rs.update();

    cr_assert_eq(rs.getElectricity(), 1);  // +2 -1 = 1
    cr_assert_eq(rs.getWater(), 1);       // +1 = 1
}

Test(ResourceSystem, HandlesMultipleSameBuildings) {
    std::unordered_map<Entity, BuildingComponent> buildings = {
        {1, BuildingComponent(BuildingType::House)},
        {2, BuildingComponent(BuildingType::House)},
        {3, BuildingComponent(BuildingType::SolarPanel)},
        {4, BuildingComponent(BuildingType::SolarPanel)},
        {5, BuildingComponent(BuildingType::WaterTank)},
        {6, BuildingComponent(BuildingType::WaterTank)}
    };

    ResourceSystem rs(buildings);
    rs.entities.insert(1);
    rs.entities.insert(2);
    rs.entities.insert(3);
    rs.entities.insert(4);
    rs.entities.insert(5);
    rs.entities.insert(6);

    rs.update();

    // Electricity: (2x +2) - (2x -1) = 2
    cr_assert_eq(rs.getElectricity(), 2);

    // Water: 1 + 1 = 2
    cr_assert_eq(rs.getWater(), 2);
}

Test(ResourceSystem, UnknownBuildingHasNoEffect) {
    std::unordered_map<Entity, BuildingComponent> buildings = {
        {1, BuildingComponent(BuildingType::Unknown)},
        {2, BuildingComponent(BuildingType::Unknown)}
    };

    ResourceSystem rs(buildings);
    rs.entities.insert(1);
    rs.entities.insert(2);

    rs.update();

    cr_assert_eq(rs.getElectricity(), 0);
    cr_assert_eq(rs.getWater(), 0);
}
