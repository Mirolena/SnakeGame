#ifndef SNAKE_H
#define SNAKE_H

#include <SDL2/SDL.h>
#include <vector>

enum class Direction { UP, DOWN, LEFT, RIGHT };

class Snake {
public:
    Snake(int tileSize, int screenWidth, int screenHeight);
    void changeDirection(Direction newDirection);
    void move();
    void grow();
    bool hasEaten(const SDL_Point& foodPosition) const;
    bool hasCollided() const;
    void render(SDL_Renderer* renderer) const;

private:
    std::vector<SDL_Point> body;
    Direction direction;
    int tileSize;
    int screenWidth;
    int screenHeight;

    SDL_Point getNextHeadPosition() const;
};

#endif
