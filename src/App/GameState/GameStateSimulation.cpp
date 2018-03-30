#include "GameStateSimulation.h"

GameStateSimulation::GameStateSimulation() = default;

GameStateSimulation::~GameStateSimulation() = default;

void GameStateSimulation::processEvent(sf::Event &event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Space) {
            regenerateMap = true;
        }
    }
}

void GameStateSimulation::update(sf::Time &time) {
    fps.update(time);

    if (regenerateMap) {
        heightMapGenerator.generate(heightMap);
        populationMapGenerator.generate(populationMap, heightMap);
        regenerateMap = false;
    } else {
        populationMapSimulator.update(time, populationMap, heightMap);
    }
}

void GameStateSimulation::draw(sf::RenderWindow &window) {
    heightMapRenderer.draw(heightMap, window);
    populationMapRenderer.draw(populationMap, window);
    fps.draw(window);
}
