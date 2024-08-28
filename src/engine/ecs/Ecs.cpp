//
// Created by Admin on 05.09.2023.
//

#include "Ecs.h"
#include "BoidSystem.h"

Ecs::Ecs() {
    systems_init();
}

Ecs::~Ecs() {
    for (Entity* entity : entities) {
        delete entity;
    }
    for (System* system : systems) {
        delete system;
    }

    delete positionSystem;
    delete physicsSystem;
    delete graphicsSystem;
}

void Ecs::systems_init() {
    //init core systems
    //TODO: complete
    auto cam = new Camera(PositionComponent(0, 0, 0));
    graphicsSystem = new GraphicsSystem(cam);
}

System * Ecs::getSystem(int id) {
    System* system = std::find_if(systems.front(), systems.back(), SystemComparator(id));

    if(system != systems.back())
        return system;
    return nullptr;
}

Entity * Ecs::getEntity(int id) {
    Entity* entity = std::find_if(entities.front(), entities.back(), EntityComparator(id));

    if(entity != entities.back())
        return entity;
    return nullptr;
}

bool Ecs::destroySystem(int id) {
    System* system = getSystem(id);

    if(!system)
        return false;
    delete system;
    return true;
}

bool Ecs::destroyEntity(int id) {
    Entity* entity = getEntity(id);

    if(!entity)
        return false;
    delete entity;
    return true;
}
