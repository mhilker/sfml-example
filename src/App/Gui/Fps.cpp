#include <cassert>
#include "Fps.h"

Fps::Fps() {
    bool status = font.loadFromFile("assets/fonts/open-sans/OpenSans-Regular.ttf");
    assert(status);

    text.setFillColor(sf::Color::White);
    text.setFont(font);
    text.setCharacterSize(20);
}

Fps::~Fps() = default;

void Fps::update(sf::Time &time) {
    std::string frames = to_string(floor(1.f/time.asSeconds()));
    text.setString(frames);
}

void Fps::draw(sf::RenderWindow &window) {
    float x = window.getSize().x - text.getGlobalBounds().width - 10;
    float y = 0;

    text.setPosition(x, y);
    window.draw(text);
}
