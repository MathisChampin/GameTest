#include <criterion/criterion.h>
#include "../../game/components/SelectableComponent.hpp"

Test(SelectableComponent, DefaultValues) {
    SelectableComponent sc;
    cr_assert_eq(sc.isSelected, false);
    cr_assert_eq(sc.isHovered, false);
}

Test(SelectableComponent, AssignValues) {
    SelectableComponent sc;
    sc.isSelected = true;
    sc.isHovered = true;

    cr_assert(sc.isSelected);
    cr_assert(sc.isHovered);
}

Test(SelectableComponent, ToggleSelection) {
    SelectableComponent sc;
    sc.isSelected = true;
    cr_assert(sc.isSelected);

    sc.isSelected = false;
    cr_assert_not(sc.isSelected);
}