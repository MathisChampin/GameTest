#ifndef POSITIONCOMPONENT_HPP_
    #define POSITIONCOMPONENT_HPP_

    #include <cstdint>

// Ce composant stocke la position et la taille d'une entité dans le monde
struct PositionComponent {
    float x = 0.0f;    // Position X en unités monde (ex: pixels)
    float y = 0.0f;    // Position Y en unités monde
    float width = 1.0f;  // Largeur (utile pour le rendu ou les collisions)
    float height = 1.0f; // Hauteur
};

#endif // POSITIONCOMPONENT_HPP_