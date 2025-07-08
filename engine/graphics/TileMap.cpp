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
    for (auto &tile : tiles)
        tile.draw(window);
    for (auto &building : buildings)
        building.draw(window);
}

void TileMap::updateHover(sf::Vector2f mousePos)
{
    for (auto &tile : tiles) {
        if (tile.contains(mousePos)) {
            if (!tile.isSelected()) {
                tile.setColor(sf::Color::Green);
            }
        } else {
            if (!tile.isSelected()) {
                tile.resetColor();
            }
        }
    }
}

void TileMap::handleClick(sf::Vector2f mousePos)
{
    for (auto &tile : tiles) {
        if (tile.contains(mousePos)) {
            tile.select();
        }
    }
}

void TileMap::placeBuilding(sf::Vector2f mousePos, BuildingType type)
{
    bool occupied = false;

    for (auto &tile : tiles) {
        if (tile.contains(mousePos)) {
            if (tile.isSelected()) {
                occupied = false;
                for (auto& b : buildings) {
                    if (b.getPosition() == tile.getPosition()) {
                        occupied = true;
                        break;
                    }
                }
                if (!occupied) {
                    buildings.emplace_back(tile.getPosition().x, tile.getPosition().y, tileSize, type);
                }
            }
        }
    }
}

void TileMap::removeBuilding(sf::Vector2f mousePos)
{
    for (auto it = buildings.begin(); it != buildings.end(); ++it) {
        if (it->contains(mousePos)) {
            buildings.erase(it);
            break;
        }
    }
}

const std::vector<Building> &TileMap::getBuildings() const
{
    return buildings;
}
