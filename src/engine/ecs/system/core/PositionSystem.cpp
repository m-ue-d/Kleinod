//
// Created by Admin on 28.08.2024.
//
#include "PositionSystem.h"
#include "Ecs.h"
#include "EntityPositionComparator.h"

PositionSystem::PositionSystem(int id) : System(id) {}


void PositionSystem::addEntity(Entity *e) {
    entities.push_back(e);
}

void PositionSystem::removeEntity(Entity *e) {
    entities.erase(
            std::remove(entities.begin(), entities.end(), e),
            entities.end()
    );
}

void PositionSystem::removeEntity(const PositionComponent& pos) {
    entities.erase(
            std::remove_if(entities.begin(), entities.end(), EntityPositionComparator(pos)),
            entities.end()
    );
}

// get
std::vector<Entity *> PositionSystem::getNeighbors(const PositionComponent& positionComponent, double radius) {
    std::vector<Entity *> neighbors;

    //TODO: Implement

    for (Entity* entity : entities) {
        neighbors.push_back(entity);
    }

    return neighbors;
}