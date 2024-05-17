#include "Snake.h"

Snake::Snake(int tileSize, int screenWidth, int screenHeight)
    : direction(Direction::RIGHT), tileSize(tileSize), screenWidth(screenWidth), screenHeight(screenHeight) {
    body.push_back({ screenWidth / 2, screenHeight / 2 });
}

void Snake::changeDirection(Direction newDirection) {
    if ((direction == Direction::UP && newDirection != Direction::DOWN) ||
        (direction == Direction::DOWN && newDirection != Direction::UP) ||
        (direction == Direction::LEFT && newDirection != Direction::RIGHT) ||
        (direction == Direction::RIGHT && newDirection != Direction::LEFT)) {
        direction = newDirection;
    }
}

void Snake::move() {
    SDL_Point nextHead = getNextHeadPosition();
    body.insert(body.begin(), nextHead);
    body.pop_back();
}

void Snake::grow() {
    SDL_Point nextHead = getNextHeadPosition();
    body.insert(body.begin(), nextHead);
}

bool Snake::hasEaten(const SDL_Point& applesPosition) const {
    return body.front().x == applesPosition.x && body.front().y == applesPosition.y;
}

bool Snake::hasCollided() const {
    const SDL_Point& head = body.front();

    if (head.x < 0 || head.x >= screenWidth || head.y < 0 || head.y >= screenHeight) {
        return true;  // Collided with wall
    }

    for (size_t i = 1; i < body.size(); ++i) {
        if (body[i].x == head.x && body[i].y == head.y) {
            return true;  // Collided with itself
        }
    }

    return false;
}

void Snake::render(SDL_Renderer* renderer) const {
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);  // Snake color
    for (const SDL_Point& segment : body) {
        SDL_Rect rect = { segment.x, segment.y, tileSize, tileSize };
        SDL_RenderFillRect(renderer, &rect);
    }
}

SDL_Point Snake::getNextHeadPosition() const {
    SDL_Point nextHead = body.front();

    switch (direction) {
    case Direction::UP:
        nextHead.y -= tileSize;
        break;
    case Direction::DOWN:
        nextHead.y += tileSize;
        break;
    case Direction::LEFT:
        nextHead.x -= tileSize;
        break;
    case Direction::RIGHT:
        nextHead.x += tileSize;
        break;
    }

    return nextHead;
}
