#include <criterion/criterion.h>
#include "../engine/ecs/SystemManager.hpp"

struct TestSystem : public ISystem {};

Test(SystemManager, RegisterAndSetSignature) {
    SystemManager sm;

    auto system = sm.registerSystem<TestSystem>();
    Signature sig;
    sig.set(0);
    sm.setSignature<TestSystem>(sig);

    cr_assert(system != nullptr);
}

Test(SystemManager, DoubleRegisterThrows) {
    SystemManager sm;
    sm.registerSystem<TestSystem>();
    cr_assert_throw(sm.registerSystem<TestSystem>(), std::runtime_error);
}

Test(SystemManager, EntityAddRemoveFromSystem) {
    SystemManager sm;
    auto system = sm.registerSystem<TestSystem>();

    Signature sig;
    sig.set(0);
    sm.setSignature<TestSystem>(sig);

    Entity e1 = 1;
    Signature eSig;
    eSig.set(0);

    sm.entitySignatureChanged(e1, eSig);
    cr_assert(system->entities.count(e1));

    eSig.reset(0);
    sm.entitySignatureChanged(e1, eSig);
    cr_assert(!system->entities.count(e1));
}

Test(SystemManager, EntityDestroyedRemovesFromSystem) {
    SystemManager sm;
    auto system = sm.registerSystem<TestSystem>();

    Signature sig;
    sig.set(0);
    sm.setSignature<TestSystem>(sig);

    Entity e1 = 1;
    Signature eSig;
    eSig.set(0);

    sm.entitySignatureChanged(e1, eSig);
    cr_assert(system->entities.count(e1));

    sm.entityDestroyed(e1);
    cr_assert(!system->entities.count(e1));
}
