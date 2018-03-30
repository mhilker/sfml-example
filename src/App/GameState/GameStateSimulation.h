#ifndef SFMLTEST_GAMESTATESIMULATION_H
#define SFMLTEST_GAMESTATESIMULATION_H

#include <iostream>
#include <App/GameState/GameState.h>
#include <App/Gui/Fps.h>
#include <App/Map/Generator/HeightMapGenerator.h>
#include <App/Map/Renderer/HeightMapRenderer.h>
#include <App/Map/Generator/PopulationMapGenerator.h>
#include <App/Map/Renderer/PopulationMapRenderer.h>
#include <App/Map/Simulator/PopulationMapSimulator.h>

class GameStateSimulation : public GameState {
public:
    GameStateSimulation();
    ~GameStateSimulation() override;
    void processEvent(sf::Event &event) override;
    void update(sf::Time &time) override;
    void draw(sf::RenderWindow &window) override;

private:
    Fps fps;

    Map heightMap;
    HeightMapGenerator heightMapGenerator;
    HeightMapRenderer heightMapRenderer;

    Map populationMap;
    PopulationMapGenerator populationMapGenerator;
    PopulationMapRenderer populationMapRenderer;
    PopulationMapSimulator populationMapSimulator;

    bool regenerateMap = true;
};


#endif //SFMLTEST_GAMESTATESIMULATION_H
