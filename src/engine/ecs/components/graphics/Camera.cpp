//
// Created by Admin on 13.08.2024.
//
#include "Camera.h"
#include "Ecs.h"

//camera always has id -1
Camera::Camera(const PositionComponent& position): Entity(-1, position), fow(1000) {}

std::vector<Entity *> Camera::visibleEntities() {
    PositionSystem *positionSystem = Ecs::shared_instance().positionSystem;

    return positionSystem->getNeighbors(position, fow);
}
