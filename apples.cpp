#include "apples.h"
#include <cstdlib>
#include <ctime>

Apples::Apples(int tileSize, int screenWidth, int screenHeight)
    : tileSize(tileSize), screenWidth(screenWidth), screenHeight(screenHeight) {
    srand(static_cast<unsigned>(time(nullptr)));
    respawn();
}

void Apples::respawn() {
    position.x = (rand() % (screenWidth / tileSize)) * tileSize;
    position.y = (rand() % (screenHeight / tileSize)) * tileSize;
}

SDL_Point Apples::getPosition() const {
    return position;
}

void Apples::render(SDL_Renderer* renderer) const {
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);  // Apples color
    SDL_Rect rect = { position.x, position.y, tileSize, tileSize };
    SDL_RenderFillRect(renderer, &rect);
}
