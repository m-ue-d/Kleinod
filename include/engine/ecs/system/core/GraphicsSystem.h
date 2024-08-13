//
// Created by fabia on 14.09.2023.
//

#pragma once
#include <SDL2/SDL.h>
#include "Camera.h"

class GraphicsSystem{
    public:
        GraphicsSystem(Camera* cam);
        ~GraphicsSystem();
        bool init(const char* title, int width, int height, int framerate);
        void frameUpdate(); //GraphicsUpdate called once every Frame. Draws every Sprite that's visible to the camera on the screen.
        void renderWhiteBox(int x, int y, int width, int height);   //TODO: test method that renders a white box

    private:
        int framerate;
        Camera* camera;
        SDL_Window* window;
        SDL_Renderer* renderer;
};
