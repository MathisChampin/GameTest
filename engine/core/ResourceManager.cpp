#include "ResourceManager.hpp"

ResourceManager::ResourceManager() : electricity(0), water(0) {}

void ResourceManager::reset()
{
    electricity = 0;
    water = 0;
}

void ResourceManager::addElectricity(int amount)
{
    electricity += amount;
}

void ResourceManager::addWater(int amount)
{
    water += amount;
}

void ResourceManager::consumeElectricity(int amount)
{
    electricity -= amount;
}

void ResourceManager::consumeWater(int amount)
{
    water -= amount;
}

int ResourceManager::getElectricity() const
{
    return electricity;
}

int ResourceManager::getWater() const
{
    return water;
}
