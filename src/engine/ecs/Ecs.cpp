//
// Created by Admin on 05.09.2023.
//

#include "Ecs.h"
#include "BoidSystem.h"

void Ecs::systems_init() {
    //init core systems
    //TODO: complete
    auto cam = new Camera(PositionComponent(0, 0, 0));
    graphicsSystem = new GraphicsSystem(cam);
}

Ecs::Ecs() {
    systems_init();
}

Ecs::~Ecs() {
    // Clean up entities
    for (Entity* entity : entities) {
        delete entity;
    }

    // Clean up systems
    delete positionSystem;
    delete physicsSystem;
    delete graphicsSystem;
}