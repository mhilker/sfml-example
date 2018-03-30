#include "HeightMapRenderer.h"

HeightMapRenderer::HeightMapRenderer() {
    ColorScale gradient;
    // Water
    gradient.insert(0.0, sf::Color(15, 66, 140));
    gradient.insert(10.0, sf::Color(15, 66, 140));
    gradient.insert(15.0, sf::Color(20, 90, 200));
    gradient.insert(20.0, sf::Color(20, 110, 230));
    gradient.insert(60.0, sf::Color(30, 115, 230));

    // Beach
    gradient.insert(65.0, sf::Color(160, 170, 35));

    // Lowlands
    // Forest
    gradient.insert(70.0, sf::Color(0, 255, 0));
    gradient.insert(75.0, sf::Color(0, 200, 0));

    // Mountain
    gradient.insert(80.00, sf::Color(128, 128, 128));
    gradient.insert(95.0, sf::Color(255, 255, 255));
    gradient.insert(100.0, sf::Color(255, 255, 255));

    gradient.fillTab(table, COLOR_COUNT);
}

HeightMapRenderer::~HeightMapRenderer() = default;

void HeightMapRenderer::draw(Map &map, sf::RenderWindow &window) {

    auto pixels = new sf::Uint8[map.getWidth() * map.getHeight() * 4];

    for (unsigned int x = 0; x < map.getWidth(); x++)
    {
        for (unsigned int y = 0; y < map.getHeight(); y++)
        {
            auto index = (int)floor(((map.get(x, y) + 1.f) / 2.f) * (float)COLOR_COUNT);
            sf::Color color = table[index];

            pixels[(x + y * map.getWidth()) * 4 + 0] = color.r;
            pixels[(x + y * map.getWidth()) * 4 + 1] = color.g;
            pixels[(x + y * map.getWidth()) * 4 + 2] = color.b;
            pixels[(x + y * map.getWidth()) * 4 + 3] = color.a;
        }
    }

    sf::Texture texture;
    texture.create(map.getWidth(), map.getHeight());
    texture.update(pixels);

    delete [] pixels;

    sf::Sprite sprite(texture);

    window.draw(sprite);
}
