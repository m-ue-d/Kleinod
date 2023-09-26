//
// Created by Admin on 24.08.2023.
//

#pragma once
#include "VelocityComponent.h"
#include "PositionComponent.h"

struct RigidbodyComponent {
    public:
        float mass; //mass is used both for gravity and dampening features, as it is easier to implement that way
        PositionComponent position;
        VelocityComponent velocity;
};
