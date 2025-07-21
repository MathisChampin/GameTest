#include <criterion/criterion.h>
#include "../../game/components/BuildingComponent.hpp"

Test(BuildingComponent, DefaultIsHouse) {
    BuildingComponent bc;
    cr_assert_eq(bc.type, BuildingType::Unknown);
    cr_assert_eq(bc.electricityConsumption, 0);
    cr_assert_eq(bc.electricityProduction, 0);
    cr_assert_eq(bc.waterProduction, 0);
    cr_assert_eq(bc.waterConsumption, 0);
}

Test(BuildingComponent, SolarPanelValues) {
    BuildingComponent bc(BuildingType::SolarPanel);
    cr_assert_eq(bc.type, BuildingType::SolarPanel);
    cr_assert_eq(bc.electricityProduction, 2);
    cr_assert_eq(bc.electricityConsumption, 0);
}

Test(BuildingComponent, WaterTankValues) {
    BuildingComponent bc(BuildingType::WaterTank);
    cr_assert_eq(bc.type, BuildingType::WaterTank);
    cr_assert_eq(bc.waterProduction, 1);
    cr_assert_eq(bc.electricityProduction, 0);
}

Test(BuildingComponent, HouseValues) {
    BuildingComponent bc(BuildingType::House);
    cr_assert_eq(bc.type, BuildingType::House);
    cr_assert_eq(bc.electricityConsumption, 1);
    cr_assert_eq(bc.waterProduction, 0);
}