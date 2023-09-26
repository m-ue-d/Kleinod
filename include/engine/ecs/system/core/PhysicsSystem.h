//
// Created by fabia on 11.09.2023.
//

#pragma once

#include <vector>
#include "System.h"
#include "Entity.h"
#include "RigidbodyComponent.h"

class PhysicsSystem : public System{
    public:
        float gravity = 0;
        void doPhysics(); //PhysicsUpdate (collisions, velocity updates, dampening, weight, position)

    private:
        std::vector<RigidbodyComponent*> rigidbodies;
};

