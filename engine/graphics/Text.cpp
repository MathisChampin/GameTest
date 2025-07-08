#include "Text.hpp"
#include <stdexcept>

Text::Text()
{
    resourceText.setCharacterSize(20);
    resourceText.setFillColor(sf::Color::White);

    selectedTypeText.setCharacterSize(20);
    selectedTypeText.setFillColor(sf::Color::White);
}

bool Text::loadFont(const std::string& path)
{
    if (!font.loadFromFile(path)) return false;

    resourceText.setFont(font);
    selectedTypeText.setFont(font);
    return true;
}

std::string Text::buildingTypeToString(BuildingType type) const
{
    switch (type) {
        case BuildingType::House: return "Maison";
        case BuildingType::SolarPanel: return "Panneau Solaire";
        case BuildingType::WaterTank: return "Chateau d'eau";
        default: return "Inconnu";
    }
}

void Text::update(const ResourceManager& rm, BuildingType selectedType, const sf::RenderWindow& window)
{
    std::string resText = "Electricite : " + std::to_string(rm.getElectricity()) +
                          " | Eau : " + std::to_string(rm.getWater());
    resourceText.setString(resText);
    float resWidth = resourceText.getLocalBounds().width;
    resourceText.setPosition(window.getSize().x - resWidth - 10.f, 10.f);

    std::string typeText = "Type selectionne : " + buildingTypeToString(selectedType);
    selectedTypeText.setString(typeText);
    float typeWidth = selectedTypeText.getLocalBounds().width;
    selectedTypeText.setPosition(window.getSize().x - typeWidth - 10.f, 40.f);
}

void Text::draw(sf::RenderWindow& window) const
{
    window.draw(resourceText);
    window.draw(selectedTypeText);
}
