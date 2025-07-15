#ifndef ENTITYMANAGER_HPP_
    #define ENTITYMANAGER_HPP_

    #include <cstdint>
    #include <queue>
    #include <unordered_set>

using Entity = std::uint32_t;
const Entity MAX_ENTITIES = 5000;

class EntityManager {
    public:
        EntityManager();

        Entity createEntity();
        void destroyEntity(Entity entity);
        bool isValid(Entity entity) const;

    private:
        std::queue<Entity> availableEntities;
        std::unordered_set<Entity> activeEntities;
        Entity nextEntity;
};

#endif // ENTITYMANAGER_HPP_
