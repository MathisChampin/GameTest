#ifndef SELECTABLECOMPONENT_HPP_
    #define SELECTABLECOMPONENT_HPP_

// Composant qui indique si une entité est sélectionnable et son état
struct SelectableComponent {
    bool isSelected = false;  // L’entité est-elle sélectionnée ?
    bool isHovered = false;   // L’entité est-elle survolée par la souris ?
};

#endif // SELECTABLECOMPONENT_HPP_
