//
// Created by fabia on 03.10.2023.
//

#pragma once
#include "Quadtree.h"
class PositionSystem : public System{
    //TODO: Fully define & Implement
    public:
        PositionComponent posOf(Entity* e);

    private:
        Quadtree quadtree;
};
