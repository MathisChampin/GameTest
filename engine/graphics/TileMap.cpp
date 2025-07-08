#include "TileMap.hpp"

TileMap::TileMap(int width, int height, float tileSize): mapWidth(width), mapHeight(height), tileSize(tileSize)
{
    
    tiles.reserve(width * height);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            float posX = x * tileSize;
            float posY = y * tileSize;
            tiles.emplace_back(posX, posY, tileSize);
        }
    }
}

void TileMap::draw(sf::RenderWindow &window)
{
    for (auto &tile : tiles) {
        tile.draw(window);
    }
}
