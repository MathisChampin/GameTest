#include "ResourceSystem.hpp"

void ResourceSystem::update()
{
    electricity = 0;
    water = 0;

    for (Entity entity : entities) {
        const auto& building = buildings.at(entity);

        electricity += building.getElectricityProduction();
        electricity -= building.getElectricityConsumption();

        water += building.getWaterProduction();
        water -= building.getWaterConsumption();
    }
}
