#include <criterion/criterion.h>
#include "../../game/systems/RenderSystem.hpp"

const std::unordered_map<Entity, PositionComponent> fakePositions;
const std::unordered_map<Entity, BuildingComponent> fakeBuildings;
const std::unordered_map<Entity, SelectableComponent> fakeSelectables;

Test(RenderSystem, GetColor_House) {
    RenderSystem rs(fakePositions, fakeBuildings, fakeSelectables);
    BuildingComponent house(BuildingType::House);
    SelectableComponent selectable;

    // Normal
    cr_assert_eq(rs.getColor(house, selectable), sf::Color::Blue);

    // Hovered
    selectable.isHovered = true;
    cr_assert_eq(rs.getColor(house, selectable), sf::Color::Green);

    // Selected
    selectable.isHovered = false;
    selectable.isSelected = true;
    cr_assert_eq(rs.getColor(house, selectable), sf::Color::Red);
}

Test(RenderSystem, GetColor_SolarPanel) {
    RenderSystem rs(fakePositions, fakeBuildings, fakeSelectables);
    BuildingComponent solar(BuildingType::SolarPanel);
    SelectableComponent selectable;

    // Normal
    cr_assert_eq(rs.getColor(solar, selectable), sf::Color::Yellow);

    // Hovered
    selectable.isHovered = true;
    cr_assert_eq(rs.getColor(solar, selectable), sf::Color::Green);

    // Selected
    selectable.isHovered = false;
    selectable.isSelected = true;
    cr_assert_eq(rs.getColor(solar, selectable), sf::Color::Red);
}

Test(RenderSystem, GetColor_WaterTank) {
    RenderSystem rs(fakePositions, fakeBuildings, fakeSelectables);
    BuildingComponent water(BuildingType::WaterTank);
    SelectableComponent selectable;

    // Normal
    cr_assert_eq(rs.getColor(water, selectable), sf::Color::Cyan);

    // Hovered
    selectable.isHovered = true;
    cr_assert_eq(rs.getColor(water, selectable), sf::Color::Green);

    // Selected
    selectable.isHovered = false;
    selectable.isSelected = true;
    cr_assert_eq(rs.getColor(water, selectable), sf::Color::Red);
}

Test(RenderSystem, GetColor_DefaultCase) {
    RenderSystem rs(fakePositions, fakeBuildings, fakeSelectables);
    BuildingComponent unknown(BuildingType::Unknown);  // valeur inconnue
    SelectableComponent selectable;

    cr_assert_eq(rs.getColor(unknown, selectable), sf::Color::White);
}
