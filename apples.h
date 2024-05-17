#ifndef APPLES_H
#define APPLES_H

#include <SDL2/SDL.h>

class Apples {
public:
    Apples(int tileSize, int screenWidth, int screenHeight);
    void respawn();
    SDL_Point getPosition() const;
    void render(SDL_Renderer* renderer) const;

private:
    SDL_Point position;
    int tileSize;
    int screenWidth;
    int screenHeight;
};

#endif
