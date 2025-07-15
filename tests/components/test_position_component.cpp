#include <criterion/criterion.h>
#include "../../game/components/PositionComponent.hpp"

Test(PositionComponent, DefaultValues) {
    PositionComponent pos;
    cr_assert_eq(pos.x, 0.0f);
    cr_assert_eq(pos.y, 0.0f);
    cr_assert_eq(pos.width, 1.0f);
    cr_assert_eq(pos.height, 1.0f);
}

Test(PositionComponent, AssignValues) {
    PositionComponent pos;
    pos.x = 10.5f;
    pos.y = 20.25f;
    pos.width = 50.0f;
    pos.height = 100.0f;

    cr_assert_eq(pos.x, 10.5f);
    cr_assert_eq(pos.y, 20.25f);
    cr_assert_eq(pos.width, 50.0f);
    cr_assert_eq(pos.height, 100.0f);
}
