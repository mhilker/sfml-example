#include "Map.h"

Map::Map() {
    clear();
}

void Map::clear() {
    for (unsigned int x = 0; x < Map::WIDTH; x++)
    {
        for (unsigned int y = 0; y < Map::HEIGHT; y++)
        {
            map[x][y] = 0.f;
        }
    }
}

void Map::set(int x, int y, float value) {

    if (x < 0) {
        x = getWidth() - x;
    }
    if (x > getWidth()) {
        x = x - getWidth();
    }
    if (y < 0) {
        y = getHeight() - y;
    }
    if (y > getHeight()) {
        y = y - getHeight();
    }

    map[x][y] = value;
}

float Map::get(int x, int y) {

    if (x < 0) {
        x = getWidth() - x;
    }
    if (x > getWidth()) {
        x = x - getWidth();
    }
    if (y < 0) {
        y = getHeight() - y;
    }
    if (y > getHeight()) {
        y = y - getHeight();
    }

    return map[x][y];
}

int Map::getWidth() {
    return Map::WIDTH;
}

int Map::getHeight() {
    return Map::HEIGHT;
}
