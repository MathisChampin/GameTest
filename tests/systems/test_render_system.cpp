#include <criterion/criterion.h>
#include "../../game/systems/RenderSystem.hpp"

Test(RenderSystem, GetColorReturnsCorrectBaseColor) {
    RenderSystem rs;

    SelectableComponent selectable;
    BuildingComponent house(BuildingType::House);
    BuildingComponent solar(BuildingType::SolarPanel);
    BuildingComponent water(BuildingType::WaterTank);

    // Cas sélectionné
    selectable.isSelected = true;
    cr_assert_eq(rs.getColor(house, selectable), sf::Color::Red);

    // Cas survolé
    selectable.isSelected = false;
    selectable.isHovered = true;
    cr_assert_eq(rs.getColor(house, selectable), sf::Color::Green);

    // Cas normal
    selectable.isHovered = false;
    cr_assert_eq(rs.getColor(house, selectable), sf::Color::Blue);
    cr_assert_eq(rs.getColor(solar, selectable), sf::Color::Yellow);
    cr_assert_eq(rs.getColor(water, selectable), sf::Color::Cyan);
}
