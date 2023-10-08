//
// Created by fabia on 26.09.2023.
//

#pragma once
#include "PositionComponent.h"
#include "Entity.h"
#include <vector>

struct Quadtree{    //TODO-Future: Maybe test the quadtree by visually representing it's structure as a test-function!
    //boundary
    PositionComponent topLeft;
    PositionComponent botRight;

    //Node
    Entity* node;

    //Quads
    Quadtree* nw;
    Quadtree* no;
    Quadtree* sw;
    Quadtree* so;
    public:
        Quadtree();
        Quadtree(PositionComponent topL, PositionComponent botR);
        void put(Entity *n);
        Entity* get(PositionComponent p);
        bool inBounds(PositionComponent p);
        std::vector<Entity*> getNeighbors(PositionComponent p, float radius);
};
