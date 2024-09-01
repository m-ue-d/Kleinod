#include <iostream>
#include "SDL.h"
#include "Boid2D.h"
#include "Camera.h"
#include "Ecs.h"

int main(int argc, char *argv[])
{
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Surface *surface;
    SDL_Event event;

    //do the following in the engine.cpp and init the engine!
    auto& graphicsSystem = Ecs::shared_instance().graphicsSystem;
    auto& positionSystem = Ecs::shared_instance().positionSystem;

    if (!graphicsSystem->init("SDL Window", 800, 600, 60)) {
        std::cerr << "Failed to initialize graphics system!" << std::endl;
        return -1;
    }

    //add test entities to positionSystem
    //TODO: make an autoIdSystem of some sort
    auto* e1 = new Entity(0);
    e1->position = { 1,1, 0 };
    auto* e2 = new Entity(0);
    e2->position = { 100,100, 0 };
    positionSystem->addEntity(e1);
    positionSystem->addEntity(e2);
    positionSystem->addEntity(graphicsSystem->getCamera());

    bool running = true;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        graphicsSystem->frameUpdate();
        SDL_Delay(16); // Simulate ~60 FPS
    }
    //TODO: make something like an engine.init()



    return 0;
}