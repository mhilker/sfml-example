#ifndef SFMLTEST_POPULATIONMAPRENDERER_H
#define SFMLTEST_POPULATIONMAPRENDERER_H


#include <App/Map/Renderer/MapRenderer.h>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RectangleShape.hpp>


class PopulationMapRenderer : public MapRenderer {
public:
    void draw(Map &map, sf::RenderWindow &window) override;

private:
    sf::RectangleShape rect;
};


#endif //SFMLTEST_POPULATIONMAPRENDERER_H
