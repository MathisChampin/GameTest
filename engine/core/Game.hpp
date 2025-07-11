#ifndef GAME_HPP_
    #define GAME_HPP_
    
    #include <SFML/Graphics.hpp>
    #include "../graphics/TileMap.hpp"
    #include "../graphics/Building.hpp"
    #include "ResourceManager.hpp"
    #include "../graphics/Text.hpp"

class Game {
    public:
        Game();
        ~Game();
    
        void run();
        void processEvents();
        void render();
        void reset();

        void updateHoverTile();
        void updateResources();
        void update();
    
        bool isEscapePressed(const sf::Event &event) const;
        bool isLeftClick(const sf::Event &event) const;
        bool isPlaceBuilding(const sf::Event &event) const; 
        bool isChangeTypeKey(const sf::Event &event) const;
        bool isResetClick(const sf::Event &event) const;
        void handleResetClick();
        void handleTileSelection();
        void handleBuildingPlacement();
        void handleTypeSwitch(const sf::Event& event);
        bool isRightClick(const sf::Event& event) const;
        void handleBuildingDeletion();

    private:
        sf::RenderWindow window;
        TileMap tileMap;
        BuildingType currentBuildingType = BuildingType::House;
        ResourceManager resourceManager;
        Text text;
};

#endif // GAME_HPP_
