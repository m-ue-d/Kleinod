//
// Created by fabia on 14.09.2023.
//

#pragma once
#include "PositionComponent.h"

//TODO: Implement a perspective Camera
struct Camera{
    public:
        Camera(const PositionComponent& position);
        ~Camera();

    private:
        PositionComponent position;
};

