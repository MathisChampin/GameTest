#include <criterion/criterion.h>
#include "../engine/core/Game.hpp"

Test(Game, DetectEscapeKey) {
    Game game;
    sf::Event event;
    event.type = sf::Event::KeyPressed;
    event.key.code = sf::Keyboard::Escape;
    cr_assert(game.isEscapePressed(event));
}

Test(Game, DetectLeftClick) {
    Game game;
    sf::Event event;
    event.type = sf::Event::MouseButtonPressed;
    event.mouseButton.button = sf::Mouse::Left;
    cr_assert(game.isLeftClick(event));
}

Test(Game, DetectRightClick) {
    Game game;
    sf::Event event;
    event.type = sf::Event::MouseButtonPressed;
    event.mouseButton.button = sf::Mouse::Right;
    cr_assert(game.isRightClick(event));
}

Test(Game, DetectPlaceBuildingKey) {
    Game game;
    sf::Event event;
    event.type = sf::Event::KeyPressed;
    event.key.code = sf::Keyboard::B;
    cr_assert(game.isPlaceBuilding(event));
}

Test(Game, DetectChangeTypeKey) {
    Game game;
    sf::Event event;
    event.type = sf::Event::KeyPressed;

    event.key.code = sf::Keyboard::A;
    cr_assert(game.isChangeTypeKey(event));

    event.key.code = sf::Keyboard::Z;
    cr_assert(game.isChangeTypeKey(event));

    event.key.code = sf::Keyboard::E;
    cr_assert(game.isChangeTypeKey(event));

    event.key.code = sf::Keyboard::B;
    cr_assert_not(game.isChangeTypeKey(event));
}
