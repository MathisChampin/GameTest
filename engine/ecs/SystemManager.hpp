#ifndef SYSTEMMANAGER_HPP_
    #define SYSTEMMANAGER_HPP_

    #include <unordered_map>
    #include <set>
    #include <memory>
    #include <typeindex>
    #include <stdexcept>

    #include "EntityManager.hpp"
    #include "ComponentManager.hpp"

class ISystem {
    public:
        std::set<Entity> entities;
        virtual ~ISystem() = default;
};

class SystemManager {
    public:
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

        template<typename T>
        void setSignature(Signature signature) {
            const std::type_index type = typeid(T);
            if (systems.find(type) == systems.end()) {
                throw std::runtime_error("System not registered!");
            }

            signatures[type] = signature;
        }

        void entityDestroyed(Entity entity) {
            for (auto const& pair : systems) {
                pair.second->entities.erase(entity);
            }
        }

        void entitySignatureChanged(Entity entity, Signature entitySignature) {
            for (auto const& pair : systems) {
                auto const& type = pair.first;
                auto const& system = pair.second;
                auto const& systemSignature = signatures[type];

                if ((entitySignature & systemSignature) == systemSignature) {
                    system->entities.insert(entity);
                } else {
                    system->entities.erase(entity);
                }
            }
        }

    private:
        std::unordered_map<std::type_index, Signature> signatures;
        std::unordered_map<std::type_index, std::shared_ptr<ISystem>> systems;
};

#endif // SYSTEMMANAGER_HPP_
