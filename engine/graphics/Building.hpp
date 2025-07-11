#ifndef BUILDING_HPP_
    #define BUILDING_HPP_

    #include <SFML/Graphics.hpp>

enum class BuildingType {
    House,
    SolarPanel,
    WaterTank
};

class Building {
    public:
        Building(float x, float y, float size, BuildingType type);

        void draw(sf::RenderWindow& window) const;
        sf::Vector2f getPosition() const;
        BuildingType getType() const;
        bool contains(sf::Vector2f point) const;

        int getElectricityProduction() const;
        int getElectricityConsumption() const;
        int getWaterProduction() const;
        int getWaterConsumption() const;
        void clear();

    private:
        sf::RectangleShape shape;
        BuildingType type;
};

#endif // BUILDING_HPP_
