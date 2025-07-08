#ifndef TILEMAP_HPP_
    #define TILEMAP_HPP_

    #include <vector>
    #include "Tile.hpp"

class TileMap {
    public:
        TileMap(int width, int height, float tileSize);

        void draw(sf::RenderWindow& window);
        void updateHover(sf::Vector2f mousePos);
        void handleClick(sf::Vector2f mousePos);

    private:
        std::vector<Tile> tiles;
        int mapWidth;
        int mapHeight;
        float tileSize;
};

#endif // TILEMAP_HPP_
