#include <random>
#include <iostream>
#include "PopulationMapSimulator.h"

void PopulationMapSimulator::update(sf::Time &time, Map &populationMap, Map &heightMap) {

    std::random_device rd;
    std::mt19937 e2(rd());
    std::uniform_real_distribution<> dir(0, 4);

    for (unsigned int x = 0; x < Map::WIDTH; x++)
    {
        for (unsigned int y = 0; y < Map::HEIGHT; y++)
        {
            auto population = populationMap.get(x, y);
            if (population < 1.f) {
                continue;
            }


            auto newPopulation = population + 1.f;
            populationMap.set(x, y, newPopulation);

            if (newPopulation < 10.f) {
                continue;
            }

            auto offsetX = 0;
            auto offsetY = 0;
            auto direction = static_cast<unsigned int>(dir(e2));

            if (direction == 0) {
                offsetX = -1;
                offsetY = -1;
            } else if (direction == 1) {
                offsetX = +1;
                offsetY = -1;
            } else if (direction == 2) {
                offsetX = -1;
                offsetY = +1;
            } else if (direction == 3) {
                offsetX = +1;
                offsetY = +1;
            }

            if (heightMap.get(x + offsetX, y + offsetY) < 0.30f) {
                continue;
            }

            populationMap.set(x, y, 5.0);
            populationMap.set(x + offsetX, y + offsetY, 5.0);
        }
    }

}
