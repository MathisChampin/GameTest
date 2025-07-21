#include <criterion/criterion.h>
#include "../../game/systems/HoverSystem.hpp"

Test(HoverSystem, Hover_SelectsCorrectEntity) {
    std::unordered_map<Entity, PositionComponent> positions = {
        {1, {10.f, 10.f, 20.f, 20.f}},
        {2, {50.f, 50.f, 20.f, 20.f}}
    };
    std::unordered_map<Entity, SelectableComponent> selectables = {
        {1, {}},
        {2, {}}
    };

    HoverSystem hs(positions, selectables);
    hs.entities.insert(1);
    hs.entities.insert(2);

    hs.update({15.f, 15.f});
    cr_assert(selectables.at(1).isHovered);
    cr_assert_not(selectables.at(2).isHovered);

    hs.update({55.f, 55.f});
    cr_assert_not(selectables.at(1).isHovered);
    cr_assert(selectables.at(2).isHovered);

    hs.update({500.f, 500.f});
    cr_assert_not(selectables.at(1).isHovered);
    cr_assert_not(selectables.at(2).isHovered);
}
