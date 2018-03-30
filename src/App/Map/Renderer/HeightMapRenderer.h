#ifndef SFMLTEST_HEIGHTMAPRENDERER_H
#define SFMLTEST_HEIGHTMAPRENDERER_H

#include <App/Map/Renderer/MapRenderer.h>
#include <App/ColorScale/ColorScale.h>
#include <SFML/Graphics.hpp>

class HeightMapRenderer : public MapRenderer {
public:
    HeightMapRenderer();
    ~HeightMapRenderer() override;
    void draw(Map &map, sf::RenderWindow &window) override;

private:
    const static int COLOR_COUNT = 256 ;
    sf::Color table[COLOR_COUNT];
};

#endif //SFMLTEST_HEIGHTMAPRENDERER_H
