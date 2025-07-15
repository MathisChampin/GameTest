#ifndef SYSTEMMANAGER_HPP_
    #define SYSTEMMANAGER_HPP_

    #include <unordered_map>
    #include <set>
    #include <memory>
    #include <typeindex>
    #include <stdexcept>

    #include "EntityManager.hpp"
    #include "ComponentManager.hpp"

// Interface générique pour tous les systèmes
class ISystem {
    public:
        std::set<Entity> entities; // Ensemble des entités gérées par ce système
        virtual ~ISystem() = default;
};

class SystemManager {
    public:
        // Enregistre un nouveau système de type T et le retourne
        template<typename T>
        std::shared_ptr<T> registerSystem() {
            const std::type_index type = typeid(T);
            if (systems.find(type) != systems.end()) {
                throw std::runtime_error("System already registered!");
            }

            auto system = std::make_shared<T>();
            systems[type] = system;
            return system;
        }

        // Définit la signature des composants que ce système surveille
        template<typename T>
        void setSignature(Signature signature) {
            const std::type_index type = typeid(T);
            if (systems.find(type) == systems.end()) {
                throw std::runtime_error("System not registered!");
            }

            signatures[type] = signature;
        }

        // Supprime une entité de tous les systèmes quand elle est détruite
        void entityDestroyed(Entity entity) {
            for (auto const& pair : systems) {
                pair.second->entities.erase(entity);
            }
        }

        // Met à jour les entités des systèmes en fonction de leur signature actuelle
        void entitySignatureChanged(Entity entity, Signature entitySignature) {
            for (auto const& pair : systems) {
                auto const& type = pair.first;
                auto const& system = pair.second;
                auto const& systemSignature = signatures[type];

                // Vérifie si l’entité correspond au système (via signature)
                if ((entitySignature & systemSignature) == systemSignature) {
                system->entities.insert(entity);
                } else {
                    system->entities.erase(entity);
                }
            }
        }

    private:
        // Associe un type de système à sa signature
        std::unordered_map<std::type_index, Signature> signatures;

        // Associe un type de système à son instance
        std::unordered_map<std::type_index, std::shared_ptr<ISystem>> systems;
};

#endif // SYSTEMMANAGER_HPP_
