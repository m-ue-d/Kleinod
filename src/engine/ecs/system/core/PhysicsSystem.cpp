//
// Created by fabia on 12.09.2023.
//
#include "PhysicsSystem.h"

void PhysicsSystem::doPhysics() {
    //collision shit
    //...
    //TODO: implement

    //gravity (if no collision occurs)
    for (RigidbodyComponent* entity:rigidbodies) {
        entity->velocity.y+= this->gravity*entity->mass;
    }
}