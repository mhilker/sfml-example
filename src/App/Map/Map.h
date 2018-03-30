#ifndef SFMLTEST_MAP_H
#define SFMLTEST_MAP_H

#include <array>
#include <SFML/Config.hpp>

class Map {
public:
    static const unsigned int WIDTH = 1000;
    static const unsigned int HEIGHT = 1000;

    Map();
    void clear();
    void set(int x, int y, float value);
    float get(int x, int y);
    int getWidth();
    int getHeight();

private:
    std::array<std::array<float, Map::HEIGHT>, Map::WIDTH> map;

};


#endif //SFMLTEST_MAP_H
