#include "HeightMapGenerator.h"

void HeightMapGenerator::generate(Map &map) {

    noise.SetSeed(rand());
    noise.SetNoiseType(FastNoise::SimplexFractal);
    noise.SetFrequency(0.0025);

    for (unsigned int x = 0; x < map.getWidth(); x++)
    {
        for (unsigned int y = 0; y < map.getHeight(); y++)
        {
            map.set(x, y, noise.GetNoise(x, y));
        }
    }
}