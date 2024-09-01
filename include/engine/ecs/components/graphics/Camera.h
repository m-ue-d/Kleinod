//
// Created by fabia on 14.09.2023.
//

#pragma once
#include "PositionComponent.h"
#include "Entity.h"
#include "PositionSystem.h"

//TODO: Implement a perspective Camera
struct Camera : public Entity{
    public:
        explicit Camera(const PositionComponent& position);
        std::vector<Entity *> visibleEntities();    //TODO: FIX

    private:
        int fow{};
};

