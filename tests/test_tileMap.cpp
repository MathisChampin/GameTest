#include <criterion/criterion.h>
#include "../engine/graphics/TileMap.hpp"

Test(TileMap, initializes_with_correct_number_of_tiles) {
    TileMap map(10, 10, 32.f);
    cr_assert_eq(map.getBuildings().size(), 0);
}

Test(TileMap, handleClick_selects_tile) {
    TileMap map(1, 1, 32.f);
    map.handleClick(sf::Vector2f(10.f, 10.f));
    map.placeBuilding(sf::Vector2f(10.f, 10.f), BuildingType::House);
    cr_assert_eq(map.getBuildings().size(), 1);
}

Test(TileMap, placeBuilding_twice_on_same_tile_only_places_one) {
    TileMap map(1, 1, 32.f);
    sf::Vector2f clickPos(10.f, 10.f);
    map.handleClick(clickPos);
    map.placeBuilding(clickPos, BuildingType::House);
    map.placeBuilding(clickPos, BuildingType::House);
    cr_assert_eq(map.getBuildings().size(), 1);
}

Test(TileMap, removeBuilding_removes_existing) {
    TileMap map(1, 1, 32.f);
    sf::Vector2f pos(10.f, 10.f);
    map.handleClick(pos);
    map.placeBuilding(pos, BuildingType::House);
    cr_assert_eq(map.getBuildings().size(), 1);
    map.removeBuilding(pos);
    cr_assert_eq(map.getBuildings().size(), 0);
}

Test(TileMap, updateHover_does_not_throw) {
    TileMap map(2, 2, 32.f);
    map.updateHover(sf::Vector2f(10.f, 10.f));
}
