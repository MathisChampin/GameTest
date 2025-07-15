#include "EntityManager.hpp"
#include <stdexcept>

EntityManager::EntityManager() : nextEntity(0)
{
    for (Entity entity = 0; entity < MAX_ENTITIES; ++entity) {
        availableEntities.push(entity);
    }
}

Entity EntityManager::createEntity()
{
    if (availableEntities.empty()) {
        throw std::runtime_error("Too many entities in use!");
    }

    Entity id = availableEntities.front();
    availableEntities.pop();
    activeEntities.insert(id);
    return id;
}

void EntityManager::destroyEntity(Entity entity)
{
    if (!isValid(entity)) {
        throw std::runtime_error("Trying to destroy invalid entity!");
    }

    activeEntities.erase(entity);
    availableEntities.push(entity);
}

bool EntityManager::isValid(Entity entity) const
{
    return activeEntities.find(entity) != activeEntities.end();
}
