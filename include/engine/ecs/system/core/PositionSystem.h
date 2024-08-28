//
// Created by fabia on 03.10.2023.
//

#pragma once
#include "Quadtree.h"
#include "System.h"

class PositionSystem : public System{
    //TODO: Fully define & Implement
    public:
        void addEntity(Entity* e);
        void removeEntity(Entity* e);
        void removeEntity(const PositionComponent& pos);

    private:
        Quadtree quadtree;
};
