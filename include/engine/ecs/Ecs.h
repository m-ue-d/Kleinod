//
// Created by Admin on 05.09.2023.
//

#pragma once
#include <vector>
#include <memory>
#include "Entity.h"
#include "System.h"
#include "PhysicsSystem.h"
#include "GraphicsSystem.h"
#include "PositionSystem.h"

class Ecs{
    public:
        static Ecs &shared_instance() {static Ecs ecs; return ecs;}
        //dynamic entities and systems
        std::vector<Entity*> entities;
        std::vector<System*> systems;
        //core systems
        PositionSystem* positionSystem;
        PhysicsSystem* physicsSystem;
        GraphicsSystem* graphicsSystem;

        ~Ecs();

    private:
        Ecs();
        void systems_init();
        System* getSystem(int id);  //TODO: Implement
        Entity* getEntity(int id);  //TODO: Implement
        bool destroySystem(int id); //TODO: Implement
        bool destroyEntity(int id); //TODO: Implement
};
