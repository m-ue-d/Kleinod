//
// Created by Admin on 28.08.2024.
//
#include "PositionSystem.h"
#include "Ecs.h"

void PositionSystem::addEntity(Entity *e) {
    quadtree.put(e);
}

void PositionSystem::removeEntity(Entity *e) {
    quadtree.remove(e->position);
}

void PositionSystem::removeEntity(const PositionComponent& pos) {
    quadtree.remove(pos);
}
