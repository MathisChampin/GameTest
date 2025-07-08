#ifndef GAME_HPP_
    #define GAME_HPP_
    
    #include <SFML/Graphics.hpp>
    #include "../graphics/TileMap.hpp"

class Game {
    public:
        Game();
        ~Game();
    
        void run();
        void processEvents();
        void update();
        void render();
    
    private:
        sf::RenderWindow window;
        TileMap tileMap;
};

#endif // GAME_HPP_
