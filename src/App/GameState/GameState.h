#ifndef SFMLTEST_GAMESTATE_H
#define SFMLTEST_GAMESTATE_H

#include <SFML/Graphics.hpp>

class GameState {
public:
    virtual ~GameState() {};
    virtual void processEvent(sf::Event &event) = 0;
    virtual void update(sf::Time &time) = 0;
    virtual void draw(sf::RenderWindow &window) = 0;
};

#endif //SFMLTEST_GAMESTATE_H
