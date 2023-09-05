//
// Created by Admin on 05.09.2023.
//

#include "Entity.h"
#include "Ecs.h"

Entity::Entity(int id) {
    this->id = id;
    Ecs::shared_instance().entities.push_back(this);
}