#ifndef ENTITYMANAGER_HPP_
    #define ENTITYMANAGER_HPP_

    #include <cstdint>
    #include <queue>
    #include <unordered_set>

// Alias pour l’identifiant d’une entité (0 ou positif)
using Entity = std::uint32_t;
// Nombre maximum d’entités supportées
const Entity MAX_ENTITIES = 5000;

class EntityManager {
public:
    EntityManager();

    // Crée une nouvelle entité et retourne son ID
    Entity createEntity();

    // Détruit une entité (libère son ID)
    void destroyEntity(Entity entity);

    // Vérifie si l’entité est actuellement active
    bool isValid(Entity entity) const;

private:
    std::queue<Entity> availableEntities; // IDs disponibles pour réutilisation
    std::unordered_set<Entity> activeEntities; // IDs actifs en cours
    Entity nextEntity; // ID suivant à allouer (non utilisé si on recycle avec la queue)
};

#endif // ENTITYMANAGER_HPP_
