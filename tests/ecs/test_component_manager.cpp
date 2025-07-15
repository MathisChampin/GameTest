#include <criterion/criterion.h>
#include "../../engine/ecs/ComponentManager.hpp"

struct TestComponent {
    int value;
};

Test(ComponentManager, RegisterAddGetRemoveComponent) {
    ComponentManager cm;
    cm.registerComponent<TestComponent>();

    Entity e1 = 1;
    TestComponent tc{42};

    cm.addComponent<TestComponent>(e1, tc);
    cr_assert_eq(cm.getComponent<TestComponent>(e1).value, 42);

    cm.removeComponent<TestComponent>(e1);
    cr_assert_throw(cm.getComponent<TestComponent>(e1), std::out_of_range);
}

Test(ComponentManager, DoubleRegisterThrows) {
    ComponentManager cm;
    cm.registerComponent<TestComponent>();
    cr_assert_throw(cm.registerComponent<TestComponent>(), std::runtime_error);
}

Test(ComponentManager, GetUnregisteredComponentThrows) {
    ComponentManager cm;
    cr_assert_throw(cm.getComponent<TestComponent>(1), std::runtime_error);
}

Test(ComponentManager, EntityDestroyedRemovesComponent) {
    ComponentManager cm;
    cm.registerComponent<TestComponent>();

    Entity e1 = 1;
    TestComponent tc{42};
    cm.addComponent<TestComponent>(e1, tc);

    cm.entityDestroyed(e1);
    cr_assert_throw(cm.getComponent<TestComponent>(e1), std::out_of_range);
}

Test(ComponentManager, MultipleComponents) {
    ComponentManager cm;
    cm.registerComponent<TestComponent>();

    Entity e1 = 1;
    TestComponent tc{42};
    cm.addComponent<TestComponent>(e1, tc);

    cr_assert_eq(cm.getComponent<TestComponent>(e1).value, 42);

    // Add another component type
    struct AnotherComponent {
        float data;
    };
    cm.registerComponent<AnotherComponent>();
    
    AnotherComponent ac{3.14f};
    cm.addComponent<AnotherComponent>(e1, ac);
    
    cr_assert_eq(cm.getComponent<AnotherComponent>(e1).data, 3.14f);
}
