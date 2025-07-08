#ifndef TILE_HPP_
    #define TILE_HPP_

#include <SFML/Graphics.hpp>

class Tile {
    public:
        Tile(float x, float y, float size);

        void draw(sf::RenderWindow& window);
        void setColor(sf::Color color);
        sf::Vector2f getPosition() const;
        bool contains(sf::Vector2f point) const;
        void resetColor();
        bool isSelected() const;
        void select();

    private:
        sf::RectangleShape shape;
        sf::Color defaultColor = sf::Color::White;
};

#endif // TILE_HPP_
