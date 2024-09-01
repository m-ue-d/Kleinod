//
// Created by Admin on 24.08.2023.
//

#pragma once
#include "VelocityComponent.h"
#include "PositionComponent.h"

//Description: Gives an entity the ability to have physical behavior inside the engine
struct RigidbodyComponent {
    public:
        double mass; //mass is used both for gravity and dampening features, as it is easier to implement that way
        VelocityComponent velocity;
};
