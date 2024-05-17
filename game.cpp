#include "game.h"
#include <iostream>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int TILE_SIZE = 20;

Game::Game() : isRunning(false), window(nullptr), renderer(nullptr), snake(nullptr), food(nullptr) {}

Game::~Game() {
    clean();
}

void Game::run() {
    initSDL();
    isRunning = true;

    snake = new Snake(TILE_SIZE, SCREEN_WIDTH, SCREEN_HEIGHT);
    food = new Apples(TILE_SIZE, SCREEN_WIDTH, SCREEN_HEIGHT);

    while (isRunning) {
        handleEvents();
        update();
        render();
        SDL_Delay(170);  // Control the speed of the game
    }

    clean();
}

void Game::initSDL() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        isRunning = false;
        return;
    }

    window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        isRunning = false;
        return;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        isRunning = false;
        return;
    }
}

void Game::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            isRunning = false;
        }
        else if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
            case SDLK_UP:
                snake->changeDirection(Direction::UP);
                break;
            case SDLK_DOWN:
                snake->changeDirection(Direction::DOWN);
                break;
            case SDLK_LEFT:
                snake->changeDirection(Direction::LEFT);
                break;
            case SDLK_RIGHT:
                snake->changeDirection(Direction::RIGHT);
                break;
            }
        }
    }
}

void Game::update() {
    snake->move();
    if (snake->hasEaten(food->getPosition())) {
        snake->grow();
        food->respawn();
    }
    if (snake->hasCollided()) {
        std::cout << "YOU LOST ;-;";
        isRunning = false;  // End the game if the snake collides with itself or the boundary
    }
}

void Game::render() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);  // Clear screen with black
    SDL_RenderClear(renderer);

    snake->render(renderer);
    food->render(renderer);

    SDL_RenderPresent(renderer);
}

void Game::clean() {
    delete snake;
    delete food;

    SDL_DestroyRenderer(renderer);
   
}
