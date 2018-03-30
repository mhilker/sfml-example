#ifndef SFMLTEST_GAME_H
#define SFMLTEST_GAME_H


#include <SFML/Graphics.hpp>
#include <iostream>
#include <App/GameState/GameState.h>
#include <App/GameState/GameStateSimulation.h>


class Game
{
public:
    Game(unsigned int height, unsigned int width);
    ~Game();
    void run();

private:
    void processEvents();
    void update();
    void render();

    sf::RenderWindow window;
    sf::Clock clock;
    sf::Time time;

    std::unique_ptr<GameState> state;
};


#endif //SFMLTEST_GAME_H
