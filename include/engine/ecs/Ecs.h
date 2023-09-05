//
// Created by Admin on 05.09.2023.
//

#ifndef KLEINOD_ECS_H
#define KLEINOD_ECS_H
#include <vector>
#include <memory>
#include "Entity.h"
#include "System.h"

struct Ecs{
    public:
        static Ecs &shared_instance() {static Ecs ecs; return ecs;}
        std::vector<Entity*> entities;
        std::vector<System*> systems;
    private:
        Ecs();
        void system_init();
};

#endif //KLEINOD_ECS_H
