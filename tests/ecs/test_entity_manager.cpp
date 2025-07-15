#include <criterion/criterion.h>
#include "../../engine/ecs/EntityManager.hpp"

Test(EntityManager, CreateAndDestroyEntity) {
    EntityManager em;

    Entity e1 = em.createEntity();
    cr_assert(em.isValid(e1));

    em.destroyEntity(e1);
    cr_assert_not(em.isValid(e1));
}

Test(EntityManager, ExceedMaxEntitiesThrows) {
    EntityManager em;

    for (Entity i = 0; i < MAX_ENTITIES; ++i) {
        em.createEntity();
    }

    cr_assert_throw(em.createEntity(), std::runtime_error);
}

Test(EntityManager, CreateEntityAfterDestroy) {
    EntityManager em;

    Entity e1 = em.createEntity();
    em.destroyEntity(e1);

    Entity e2 = em.createEntity();
    cr_assert_not(e1 == e2);
    cr_assert(em.isValid(e2));
}

Test(EntityManager, IsValidReturnsTrueForActiveEntity) {
    EntityManager em;

    Entity e1 = em.createEntity();
    cr_assert(em.isValid(e1));

    em.destroyEntity(e1);
    cr_assert_not(em.isValid(e1));
}

Test(EntityManager, IsValidReturnsFalseForDestroyedEntity) {
    EntityManager em;

    Entity e1 = em.createEntity();
    em.destroyEntity(e1);

    cr_assert_not(em.isValid(e1));
}

Test(EntityManager, CreateMultipleEntities) {
    EntityManager em;

    Entity e1 = em.createEntity();
    Entity e2 = em.createEntity();
    cr_assert_not(e1 == e2);
    cr_assert(em.isValid(e1));
    cr_assert(em.isValid(e2));

    em.destroyEntity(e1);
    em.destroyEntity(e2);
}

Test(EntityManager, DestroyInvalidEntityThrows) {
    EntityManager em;

    Entity e1 = em.createEntity();
    em.destroyEntity(e1);

    cr_assert_throw(em.destroyEntity(e1), std::runtime_error);
}