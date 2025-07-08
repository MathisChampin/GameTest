#ifndef TILEMAP_HPP_
    #define TILEMAP_HPP_

    #include <vector>
    #include "Tile.hpp"
    #include "Building.hpp"

class TileMap {
    public:
        TileMap(int width, int height, float tileSize);

        void draw(sf::RenderWindow &window);
        void updateHover(sf::Vector2f mousePos);
        void handleClick(sf::Vector2f mousePos);
        void placeBuilding(sf::Vector2f mousePos);

    private:
        std::vector<Tile> tiles;
        int mapWidth;
        int mapHeight;
        float tileSize;
        std::vector<Building> buildings;
};

#endif // TILEMAP_HPP_
