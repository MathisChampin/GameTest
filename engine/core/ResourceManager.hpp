#ifndef RESOURCEMANAGER_HPP_
    #define RESOURCEMANAGER_HPP_

class ResourceManager {
    public:
        ResourceManager();

        void reset();
        void addElectricity(int amount);
        void addWater(int amount);
        void consumeElectricity(int amount);
        void consumeWater(int amount);

        int getElectricity() const;
        int getWater() const;

    private:
        int electricity;
        int water;
};

#endif // RESOURCEMANAGER_HPP_
