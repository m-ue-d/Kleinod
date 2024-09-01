//
// Created by Admin on 28.08.2024.
//
#include "PositionSystem.h"
#include "Ecs.h"

PositionSystem::PositionSystem(int id) : System(id) {}


void PositionSystem::addEntity(Entity *e) {
    quadtree.put(e);
}

void PositionSystem::removeEntity(Entity *e) {
    quadtree.remove(e->position);
}

void PositionSystem::removeEntity(const PositionComponent& pos) {
    quadtree.remove(pos);
}

std::vector<Entity *> PositionSystem::getNeighbors(const PositionComponent& positionComponent, double radius) {
    std::vector<Entity *> neighbors;
    quadtree.getNeighborsRecursive(positionComponent, radius, neighbors);

    return neighbors;
}