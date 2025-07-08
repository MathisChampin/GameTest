#ifndef GAME_HPP_
    #define GAME_HPP_
    
    #include <SFML/Graphics.hpp>
    #include "../graphics/TileMap.hpp"
    #include "../graphics/Building.hpp"

class Game {
    public:
        Game();
        ~Game();
    
        void run();
        void processEvents();
        void update();
        void render();

        bool isEscapePressed(const sf::Event &event) const;
        bool isLeftClick(const sf::Event &event) const;
        bool isPlaceBuilding(const sf::Event &event) const; 
        bool isChangeTypeKey(const sf::Event &event) const;
        void handleTileSelection();
        void handleBuildingPlacement();
        void handleTypeSwitch(const sf::Event& event);

    private:
        sf::RenderWindow window;
        TileMap tileMap;
        BuildingType currentBuildingType = BuildingType::House;
};

#endif // GAME_HPP_
