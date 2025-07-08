#ifndef BUILDING_HPP_
    #define BUILDING_HPP_

    #include <SFML/Graphics.hpp>

class Building {
    public:
        Building(float x, float y, float size, sf::Color color);

        void draw(sf::RenderWindow& window) const;
        sf::Vector2f getPosition() const;

    private:
        sf::RectangleShape shape;
};

#endif // BUILDING_HPP_
