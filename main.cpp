#include <iostream>
#include "SDL.h"
#include "Boid2D.h"

int main(int argc, char *argv[])
{
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Surface *surface;
    SDL_Event event;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL: %s", SDL_GetError());
        return 3;
    }

    if (SDL_CreateWindowAndRenderer(1000, 600, SDL_WINDOW_RESIZABLE, &window, &renderer)) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window and renderer: %s", SDL_GetError());
        return 3;
    }

    while (true) {
        SDL_PollEvent(&event);
        if (event.type == SDL_QUIT) {
            break;
        }
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);

        //Test simple boidsystem
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}


//#include "Camera.h"
//#include "GraphicsSystem.h"
//
////
//// Created by Admin on 13.08.2024.
////
//int main(int argc, char* argv[]) {  //TODO: This is just a test method. make this thing real!
//    Camera cam; // Assuming you have a Camera class
//    GraphicsSystem graphics(&cam);
//
//    if (!graphics.init("SDL Window", 800, 600, 60)) {
//        std::cerr << "Failed to initialize graphics system!" << std::endl;
//        return -1;
//    }
//
//    bool running = true;
//    SDL_Event event;
//
//    while (running) {
//        while (SDL_PollEvent(&event)) {
//            if (event.type == SDL_QUIT) {
//                running = false;
//            }
//        }
//
//        graphics.frameUpdate();
//        SDL_Delay(16); // Simulate ~60 FPS
//    }
//
//    return 0;
//}
//
