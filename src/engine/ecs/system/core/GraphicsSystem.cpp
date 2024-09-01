//
// Created by fabia on 14.09.2023.
//
#include "GraphicsSystem.h"
#include <iostream>

GraphicsSystem::GraphicsSystem(int id, Camera* cam): System(id), camera(cam), window(nullptr), renderer(nullptr) {}

GraphicsSystem::~GraphicsSystem() {
    //destroy renderer and window
    if (renderer != nullptr) {
        SDL_DestroyRenderer(renderer);
    }
    if (window != nullptr) {
        SDL_DestroyWindow(window);
    }
    //quit SDL subsystems
    SDL_Quit();
}

bool GraphicsSystem::init(const char* title, int width, int height, int framerate) {    //TODO: Use framerate
    //initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    //create window
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    //create renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    return true;
}

void GraphicsSystem::frameUpdate() {
    SDL_RenderClear(renderer);

    //render objects
    std::vector<Entity *> entities = camera->visibleEntities();
    for (Entity* entity : entities) {
        std::cout << entity->id << " x:" << entity->position.getX() << " y:" << entity->position.getY() << std::endl;
        renderBox((int)entity->position.getX() - 25, (int)entity->position.getY() - 25, 50, 50);
    }

    SDL_RenderPresent(renderer);
}

//test function
void GraphicsSystem::renderBox(int x, int y, int width, int height) {
    // Set draw color to white
    SDL_SetRenderDrawColor(renderer, 255, 177, 0, 255);

    // Create a rectangle for the white box
    SDL_Rect box = { x, y, width, height };

    // Render the white box
    SDL_RenderFillRect(renderer, &box);

    // Reset draw color to black for future operations
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}

Camera *GraphicsSystem::getCamera() {
    return camera;
}
