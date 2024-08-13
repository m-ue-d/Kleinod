//
// Created by fabia on 14.09.2023.
//
#include "GraphicsSystem.h"
#include <iostream>

// Constructor
GraphicsSystem::GraphicsSystem(Camera* cam) : camera(cam), window(nullptr), renderer(nullptr) {}

// Destructor
GraphicsSystem::~GraphicsSystem() {
    // Destroy renderer and window
    if (renderer != nullptr) {
        SDL_DestroyRenderer(renderer);
    }
    if (window != nullptr) {
        SDL_DestroyWindow(window);
    }
    // Quit SDL subsystems
    SDL_Quit();
}

// Initialization function
bool GraphicsSystem::init(const char* title, int width, int height, int framerate) {    //TODO: Use framerate
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    // Create window
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    // Create renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    // Set the renderer's draw color to black (background color)
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    return true;
}

// Frame update function
void GraphicsSystem::frameUpdate() {
    // Clear the screen with the background color
    SDL_RenderClear(renderer);

    // Render a white box (example at position (100, 100) with width 200 and height 150)
    renderWhiteBox(100, 100, 200, 150);

    // Present the renderer's contents to the window
    SDL_RenderPresent(renderer);
}

// Function to render a white box
void GraphicsSystem::renderWhiteBox(int x, int y, int width, int height) {
    // Set draw color to white
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    // Create a rectangle for the white box
    SDL_Rect whiteBox = { x, y, width, height };

    // Render the white box
    SDL_RenderFillRect(renderer, &whiteBox);

    // Reset draw color to black for future operations
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}
