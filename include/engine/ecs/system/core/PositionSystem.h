//
// Created by fabia on 03.10.2023.
//

#pragma once

#include <vector>
#include "System.h"
#include "Entity.h"

class PositionSystem : public System {
    //TODO: Fully define & Implement
    public:
    explicit PositionSystem(int id);

    void addEntity(Entity* e);
    void removeEntity(Entity* e);
    void removeEntity(const PositionComponent& pos);
    std::vector<Entity*> getNeighbors(const PositionComponent& positionComponent, double radius);

    private:
        std::vector<Entity*> entities;
};