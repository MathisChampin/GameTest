#ifndef TILE_HPP_
    #define TILE_HPP_

#include <SFML/Graphics.hpp>

class Tile {
    public:
        Tile(float x, float y, float size);

        void draw(sf::RenderWindow& window);
        void setColor(sf::Color color);
        sf::Vector2f getPosition() const;

    private:
        sf::RectangleShape shape;
};

#endif // TILE_HPP_
