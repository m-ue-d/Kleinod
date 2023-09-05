//
// Created by Admin on 24.08.2023.
//

#ifndef KLEINOD_RIGIDBODYCOMPONENT_H
#define KLEINOD_RIGIDBODYCOMPONENT_H
#include "VelocityComponent.h"
#include "PositionComponent.h"

struct RigidbodyComponent {
    public:
        float weight;
        PositionComponent position;
        VelocityComponent velocity;
};


#endif //KLEINOD_RIGIDBODYCOMPONENT_H
