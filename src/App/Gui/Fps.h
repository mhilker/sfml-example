#ifndef SFMLTEST_FPS_H
#define SFMLTEST_FPS_H

#include <SFML/Graphics.hpp>
#include <Helper/String.h>


class Fps {
public:
    Fps();
    ~Fps();
    void update(sf::Time &time);
    void draw(sf::RenderWindow &window);

private:
    sf::Font font;
    sf::Text text;
};


#endif //SFMLTEST_FPS_H
