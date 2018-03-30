#include <random>
#include <iostream>
#include "PopulationMapGenerator.h"

void PopulationMapGenerator::generate(Map &populationMap, Map &heightMap) {

    // Devices
    std::random_device rd;

    // Engines
    std::mt19937 e2(rd());
    //std::knuth_b e2(rd());
    //std::default_random_engine e2(rd()) ;

    // Distribtuions
    std::uniform_real_distribution<> distX(0, populationMap.getWidth());
    std::uniform_real_distribution<> distY(0, populationMap.getHeight());
    //std::normal_distribution<> dist(2, 2);
    //std::student_t_distribution<> dist(5);
    //std::poisson_distribution<> dist(2);
    //std::extreme_value_distribution<> dist(0,2);

    unsigned int hits = 0;

    populationMap.clear();

    while (hits < 100) {
        auto x = static_cast<unsigned int>(distX(e2));
        auto y = static_cast<unsigned int>(distY(e2));

        auto height = heightMap.get(x, y);

        if (height > 0.5f) {
            populationMap.set(x, y, 1.f);
            hits++;
        }
    }
}
