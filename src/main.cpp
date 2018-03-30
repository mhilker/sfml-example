#include <App/Game/Game.h>

int main()
{
    unsigned int width = 1920;
    unsigned int height = 1080;

    Game game(width, height);
    game.run();

    return 0;
}
