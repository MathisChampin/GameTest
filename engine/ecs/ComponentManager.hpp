#ifndef COMPONENTMANAGER_HPP_
    #define COMPONENTMANAGER_HPP_

    #include <unordered_map>
    #include <typeindex>
    #include <memory>
    #include <stdexcept>
    #include <bitset>
    #include <queue>
    #include <unordered_set>

    #include "EntityManager.hpp"

const std::size_t MAX_COMPONENTS = 64;
using ComponentType = std::uint8_t;
using Signature = std::bitset<MAX_COMPONENTS>;

// Base interface pour les ComponentArrays
class IComponentArray {
    public:
        virtual ~IComponentArray() = default;
        virtual void entityDestroyed(Entity entity) = 0;
};

// Template de stockage des composants pour un type donné
template<typename T>
class ComponentArray : public IComponentArray {
    public:
        void insertData(Entity entity, T component) {
            entityToComponent[entity] = component;
        }

        void removeData(Entity entity) {
            entityToComponent.erase(entity);
        }

        T& getData(Entity entity) {
            return entityToComponent.at(entity);
        }

        void entityDestroyed(Entity entity) override {
            entityToComponent.erase(entity);
        }

    private:
        std::unordered_map<Entity, T> entityToComponent;
};

class ComponentManager {
    public:
        template<typename T>
        void registerComponent() {
            const std::type_index type = typeid(T);

            if (componentTypes.find(type) != componentTypes.end()) {
                throw std::runtime_error("Component already registered!");
            }

            componentTypes[type] = nextComponentType;
            componentArrays[type] = std::make_shared<ComponentArray<T>>();
            ++nextComponentType;
        }

        template<typename T>
        ComponentType getComponentType() {
            const std::type_index type = typeid(T);

            if (componentTypes.find(type) == componentTypes.end()) {
                throw std::runtime_error("Component not registered!");
            }

            return componentTypes[type];
        }

        template<typename T>
        void addComponent(Entity entity, T component) {
            getComponentArray<T>()->insertData(entity, component);
        }

        template<typename T>
        void removeComponent(Entity entity) {
            getComponentArray<T>()->removeData(entity);
        }

        template<typename T>
        T& getComponent(Entity entity) {
            return getComponentArray<T>()->getData(entity);
        }

        void entityDestroyed(Entity entity) {
            for (auto const& pair : componentArrays) {
            pair.second->entityDestroyed(entity);
            }
        }

    private:
        std::unordered_map<std::type_index, ComponentType> componentTypes;
        std::unordered_map<std::type_index, std::shared_ptr<IComponentArray>> componentArrays;
        ComponentType nextComponentType = 0;

        template<typename T>
        std::shared_ptr<ComponentArray<T>> getComponentArray() {
            const std::type_index type = typeid(T);

            if (componentTypes.find(type) == componentTypes.end()) {
                throw std::runtime_error("Component not registered!");
            }

            return std::static_pointer_cast<ComponentArray<T>>(componentArrays[type]);
        }
};

#endif // COMPONENTMANAGER_HPP_
