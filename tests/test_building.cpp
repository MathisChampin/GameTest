#include <criterion/criterion.h>
#include "../engine/graphics/Building.hpp"

Test(Building, constructor_sets_position_and_type) {
    Building b(10.f, 20.f, 32.f, BuildingType::House);
    cr_assert_eq(b.getPosition().x, 10.f);
    cr_assert_eq(b.getPosition().y, 20.f);
    cr_assert_eq(b.getType(), BuildingType::House);
}

Test(Building, contains_point_inside_and_outside) {
    Building b(0.f, 0.f, 32.f, BuildingType::House);
    cr_assert(b.contains({10.f, 10.f}));
    cr_assert_not(b.contains({40.f, 40.f}));
}

Test(Building, electricity_production_and_consumption) {
    Building house(0.f, 0.f, 32.f, BuildingType::House);
    Building panel(0.f, 0.f, 32.f, BuildingType::SolarPanel);
    Building tank(0.f, 0.f, 32.f, BuildingType::WaterTank);

    cr_assert_eq(house.getElectricityConsumption(), 1);
    cr_assert_eq(house.getElectricityProduction(), 0);

    cr_assert_eq(panel.getElectricityProduction(), 2);
    cr_assert_eq(panel.getElectricityConsumption(), 0);

    cr_assert_eq(tank.getElectricityProduction(), 0);
    cr_assert_eq(tank.getElectricityConsumption(), 0);
}

Test(Building, water_production_and_consumption) {
    Building house(0.f, 0.f, 32.f, BuildingType::House);
    Building panel(0.f, 0.f, 32.f, BuildingType::SolarPanel);
    Building tank(0.f, 0.f, 32.f, BuildingType::WaterTank);

    cr_assert_eq(house.getWaterProduction(), 0);
    cr_assert_eq(panel.getWaterProduction(), 0);
    cr_assert_eq(tank.getWaterProduction(), 1);

    cr_assert_eq(house.getWaterConsumption(), 0);
    cr_assert_eq(panel.getWaterConsumption(), 0);
    cr_assert_eq(tank.getWaterConsumption(), 0);
}
