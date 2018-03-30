#include "PopulationMapRenderer.h"

void PopulationMapRenderer::draw(Map &map, sf::RenderWindow &window) {

    rect.setFillColor(sf::Color::Red);
    rect.setSize(sf::Vector2f(1, 1));

    for (unsigned int x = 0; x < map.getWidth(); x++)
    {
        for (unsigned int y = 0; y < map.getHeight(); y++)
        {
            float population = map.get(x, y);

            if (population > 0.f) {
                rect.setPosition(x, y);
                window.draw(rect);
            }
        }
    }
}
