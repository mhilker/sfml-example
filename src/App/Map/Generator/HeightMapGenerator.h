#ifndef SFMLTEST_HEIGHTMAPGENERATOR_H
#define SFMLTEST_HEIGHTMAPGENERATOR_H

#include <App/Map/Map.h>
#include <FastNoise.h>

class HeightMapGenerator {
public:
    void generate(Map &map);

private:
    FastNoise noise;
};


#endif //SFMLTEST_HEIGHTMAPGENERATOR_H
