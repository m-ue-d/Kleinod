//
// Created by fabia on 14.09.2023.
//

#pragma once
#include <SDL2/SDL.h>
#include "Camera.h"
#include "PositionSystem.h"

class GraphicsSystem: public System{
    public:
        explicit GraphicsSystem(int id, Camera* cam);
        ~GraphicsSystem() override;
        bool init(const char* title, int width, int height, int framerate);
        void frameUpdate();
        void renderBox(int x, int y, int width, int height);
        Camera* getCamera();

    private:
        int framerate{};
        Camera* camera;
        SDL_Window* window;
        SDL_Renderer* renderer;
};
