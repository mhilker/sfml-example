#ifndef SFMLTEST_POPULATIONMAPSIMULATOR_H
#define SFMLTEST_POPULATIONMAPSIMULATOR_H


#include <SFML/System/Time.hpp>
#include <App/Map/Map.h>

class PopulationMapSimulator {
public:
    void update(sf::Time &time, Map &populationMap, Map &heightMap);
};


#endif //SFMLTEST_POPULATIONMAPSIMULATOR_H
