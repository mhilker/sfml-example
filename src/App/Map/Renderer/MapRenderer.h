#ifndef SFMLTEST_MAPRENDERER_H
#define SFMLTEST_MAPRENDERER_H


#include <SFML/Graphics/RenderWindow.hpp>
#include <App/Map/Map.h>


class MapRenderer {
public:
    virtual ~MapRenderer() {};
    virtual void draw(Map &map, sf::RenderWindow &window) = 0;
};


#endif //SFMLTEST_MAPRENDERER_H
