#include "Game.h"

Game::Game(unsigned int width, unsigned int height) : window(sf::VideoMode(width, height), "Worlds")
{
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);

    state = std::make_unique<GameStateSimulation>();
}

Game::~Game() = default;

void Game::run()
{
    while (window.isOpen())
    {
        processEvents();
        update();
        render();
    }
}

void Game::processEvents()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::Closed:
                window.close();
                break;
            default:
                state->processEvent(event);
                break;
        }
    }
}

void Game::update()
{
    time = clock.getElapsedTime();
    clock.restart().asSeconds();

    state->update(time);
}

void Game::render()
{
    window.clear();
    state->draw(window);
    window.display();
}
