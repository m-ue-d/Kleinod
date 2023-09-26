//
// Created by fabia on 14.09.2023.
//

#pragma once
#include "Camera.h"

class GraphicsSystem{
    public:
        int framerate = 60;
        Camera* camera;
        void frameUpdate(); //GraphicsUpdate called once every Frame. Draws every Sprite that's visible to the camera on the screen.
        GraphicsSystem(Camera* cam);
};
