#include <criterion/criterion.h>
#include <SFML/Graphics.hpp>
#include "../engine/graphics/Tile.hpp"

Test(Tile, constructor_sets_correct_position) {
    Tile tile(10.f, 20.f, 30.f);
    sf::Vector2f pos = tile.getPosition();
    cr_assert_eq(pos.x, 10.f);
    cr_assert_eq(pos.y, 20.f);
}

Test(Tile, contains_point_inside) {
    Tile tile(0.f, 0.f, 50.f);
    sf::Vector2f point(25.f, 25.f);
    cr_assert(tile.contains(point));
}

Test(Tile, does_not_contain_point_outside) {
    Tile tile(0.f, 0.f, 50.f);
    sf::Vector2f point(100.f, 100.f);
    cr_assert_not(tile.contains(point));
}

Test(Tile, setColor_changes_color) {
    Tile tile(0.f, 0.f, 50.f);
    tile.setColor(sf::Color::Green);
    tile.select();
    cr_assert(tile.isSelected());
}

Test(Tile, resetColor_sets_white) {
    Tile tile(0.f, 0.f, 50.f);
    tile.setColor(sf::Color::Blue);
    tile.resetColor();
    cr_assert_not(tile.isSelected());
}

Test(Tile, select_sets_red) {
    Tile tile(0.f, 0.f, 50.f);
    tile.select();
    cr_assert(tile.isSelected());
}
