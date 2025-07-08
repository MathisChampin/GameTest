#include <criterion/criterion.h>
#include "../engine/graphics/Text.hpp"
#include "../engine/core/ResourceManager.hpp"
#include <SFML/Graphics/RenderWindow.hpp>

Test(Text, buildingTypeToString_returns_correct_string) {
    Text txt;

    cr_assert_eq(txt.buildingTypeToString(BuildingType::House), "Maison");
    cr_assert_eq(txt.buildingTypeToString(BuildingType::SolarPanel), "Panneau Solaire");
    cr_assert_eq(txt.buildingTypeToString(BuildingType::WaterTank), "Chateau d'eau");
    cr_assert_eq(txt.buildingTypeToString(static_cast<BuildingType>(-1)), "Inconnu");
}

Test(Text, loadFont_returns_false_on_invalid_path) {
    Text txt;
    cr_assert_not(txt.loadFont("invalid/path/to/font.ttf"));
}

Test(Text, update_does_not_throw) {
    Text txt;
    ResourceManager rm;
    rm.addElectricity(5);
    rm.addWater(3);

    txt.loadFont("assets/fonts/LibertinusMono-Regular.ttf");

    sf::RenderWindow window(sf::VideoMode(800, 600), "Dummy");
    txt.update(rm, BuildingType::House, window);
    cr_assert(1);
}
