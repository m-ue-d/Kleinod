//
// Created by Admin on 05.09.2023.
//

#include "Ecs.h"
#include "BoidSystem.h"

void Ecs::system_init() {
    auto *boidSystem = new BoidSystem(0);
    boidSystem->init(10);
    systems.push_back(boidSystem);
}

Ecs::Ecs() = default;
