#ifndef COMPONENTMANAGER_HPP_
    #define COMPONENTMANAGER_HPP_

    #include <unordered_map>
    #include <typeindex>
    #include <memory>
    #include <stdexcept>
    #include <bitset>

    #include "EntityManager.hpp"

// Nombre max de composants différents qu'on peut enregistrer
const std::size_t MAX_COMPONENTS = 64;

// Type pour identifier un composant (0,1,2,...)
using ComponentType = std::uint8_t;

// Signature = bitmap pour savoir quels composants une entité possède
using Signature = std::bitset<MAX_COMPONENTS>;

// Interface générique pour tout tableau de composants
class IComponentArray {
    public:
        virtual ~IComponentArray() = default;
        virtual void entityDestroyed(Entity entity) = 0;
};

// Tableau de composants pour un type spécifique T
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
        // Enregistre un type de composant
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

        // Retourne l’identifiant interne d’un type de composant
        template<typename T>
        ComponentType getComponentType() {
            const std::type_index type = typeid(T);

            if (componentTypes.find(type) == componentTypes.end()) {
                throw std::runtime_error("Component not registered!");
            }

            return componentTypes[type];
        }

        // Ajoute un composant à une entité
        template<typename T>
        void addComponent(Entity entity, T component) {
            getComponentArray<T>()->insertData(entity, component);
        }

        // Retire un composant d’une entité
        template<typename T>
        void removeComponent(Entity entity) {
            getComponentArray<T>()->removeData(entity);
        }

        // Récupère un composant d’une entité
        template<typename T>
        T& getComponent(Entity entity) {
            return getComponentArray<T>()->getData(entity);
        }

        // Supprime les composants liés à une entité détruite
        void entityDestroyed(Entity entity) {
            for (auto const& pair : componentArrays) {
                pair.second->entityDestroyed(entity);
            }
        }

    private:
        // Associe chaque type de composant (ex: PositionComponent) à un ID numérique unique (ComponentType)
        std::unordered_map<std::type_index, ComponentType> componentTypes;

        // Contient, pour chaque type de composant, son tableau de stockage (ComponentArray<T>) partagé
        std::unordered_map<std::type_index, std::shared_ptr<IComponentArray>> componentArrays;

        // ID suivant à attribuer au prochain type de composant enregistré (ex: 0, 1, 2, ...)
        ComponentType nextComponentType = 0;


        // Récupère le tableau de composants pour un type T
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
