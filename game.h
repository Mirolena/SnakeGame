#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include "snake.h"
#include "apples.h"

class Game {
public:
    Game();
    ~Game();
    void run();

private:
    void initSDL();
    void handleEvents();
    void update();
    void render();
    void clean();

    bool isRunning;
    SDL_Window* window;
    SDL_Renderer* renderer;

    Snake* snake;
    Apples * food;
};

#endif
