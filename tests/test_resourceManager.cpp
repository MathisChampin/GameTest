#include <criterion/criterion.h>
#include "../engine/core/ResourceManager.hpp"

Test(ResourceManager, InitialStateIsZero) {
    ResourceManager rm;
    cr_assert_eq(rm.getElectricity(), 0);
    cr_assert_eq(rm.getWater(), 0);
}

Test(ResourceManager, AddResources) {
    ResourceManager rm;
    rm.addElectricity(5);
    rm.addWater(3);
    cr_assert_eq(rm.getElectricity(), 5);
    cr_assert_eq(rm.getWater(), 3);
}

Test(ResourceManager, ConsumeResources) {
    ResourceManager rm;
    rm.addElectricity(10);
    rm.addWater(8);
    rm.consumeElectricity(4);
    rm.consumeWater(5);
    cr_assert_eq(rm.getElectricity(), 6);
    cr_assert_eq(rm.getWater(), 3);
}

Test(ResourceManager, Reset) {
    ResourceManager rm;
    rm.addElectricity(10);
    rm.addWater(5);
    rm.reset();
    cr_assert_eq(rm.getElectricity(), 0);
    cr_assert_eq(rm.getWater(), 0);
}
