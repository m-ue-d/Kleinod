//
// Created by Admin on 05.09.2023.
//

#include "Entity.h"
#include "Ecs.h"

Entity::Entity(int id) : id(id), position({0,0,0}){
    Ecs::shared_instance().entities.push_back(this);
}

Entity::Entity(int id, PositionComponent p) : id(id), position(p){
    Ecs::shared_instance().entities.push_back(this);
}
