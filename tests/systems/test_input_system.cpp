#include <criterion/criterion.h>
#include "../../game/systems/InputSystem.hpp"

Test(InputSystem, LeftClick_SelectsEntity) {
    std::unordered_map<Entity, PositionComponent> positions = {
        {1, {10.f, 10.f, 20.f, 20.f}},
        {2, {50.f, 50.f, 20.f, 20.f}}
    };
    std::unordered_map<Entity, SelectableComponent> selectables = {
        {1, {}},
        {2, {}}
    };

    InputSystem is(positions, selectables);
    is.entities.insert(1);
    is.entities.insert(2);

    is.handleLeftClick({15.f, 15.f});  // Inside entity 1
    cr_assert(selectables.at(1).isSelected);
    cr_assert_not(selectables.at(2).isSelected);

    is.handleLeftClick({55.f, 55.f});  // Inside entity 2
    cr_assert_not(selectables.at(1).isSelected);
    cr_assert(selectables.at(2).isSelected);
}

Test(InputSystem, RightClick_DeselectsAll) {
    std::unordered_map<Entity, PositionComponent> positions = {
        {1, {10.f, 10.f, 20.f, 20.f}},
        {2, {50.f, 50.f, 20.f, 20.f}}
    };
    std::unordered_map<Entity, SelectableComponent> selectables = {
        {1, {.isSelected = true}},
        {2, {.isSelected = true}}
    };

    InputSystem is(positions, selectables);
    is.entities.insert(1);
    is.entities.insert(2);

    is.handleRightClick();
    cr_assert_not(selectables.at(1).isSelected);
    cr_assert_not(selectables.at(2).isSelected);
}

Test(InputSystem, PlaceBuildingFlag_SetsTrue) {
    std::unordered_map<Entity, PositionComponent> positions;
    std::unordered_map<Entity, SelectableComponent> selectables;

    InputSystem is(positions, selectables);
    cr_assert_not(is.shouldPlaceBuilding());

    is.handlePlaceBuilding();
    cr_assert(is.shouldPlaceBuilding());
}

Test(InputSystem, ResetFlag_SetsTrue) {
    std::unordered_map<Entity, PositionComponent> positions;
    std::unordered_map<Entity, SelectableComponent> selectables;

    InputSystem is(positions, selectables);
    cr_assert_not(is.shouldReset());

    is.handleReset();
    cr_assert(is.shouldReset());
}

Test(InputSystem, TypeSwitch_ChangesBuildingType) {
    std::unordered_map<Entity, PositionComponent> positions;
    std::unordered_map<Entity, SelectableComponent> selectables;

    InputSystem is(positions, selectables);

    is.handleTypeSwitch(sf::Keyboard::A);
    cr_assert_eq(is.getCurrentBuildingType(), BuildingType::House);

    is.handleTypeSwitch(sf::Keyboard::Z);
    cr_assert_eq(is.getCurrentBuildingType(), BuildingType::SolarPanel);

    is.handleTypeSwitch(sf::Keyboard::E);
    cr_assert_eq(is.getCurrentBuildingType(), BuildingType::WaterTank);
}
