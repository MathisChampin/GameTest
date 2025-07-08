#ifndef TEXT_HPP_
    #define TEXT_HPP_

    #include <SFML/Graphics.hpp>
    #include <string>
    #include "../core/ResourceManager.hpp"
    #include "Building.hpp"

class Text {
    public:
        Text();
        bool loadFont(const std::string& path);
        void update(const ResourceManager& rm, BuildingType selectedType, const sf::RenderWindow& window);
        void draw(sf::RenderWindow& window) const;
        std::string buildingTypeToString(BuildingType type) const;

    private:
        sf::Font font;
        sf::Text resourceText;
        sf::Text selectedTypeText;
};

#endif // TEXT_HPP_
