//
// Created by fabia on 26.09.2023.
//

#pragma once
#include "PositionComponent.h"
#include "Entity.h"
#include <vector>

struct Quadtree{
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
        void getNeighborsRecursive(PositionComponent p, float radius, std::vector<Entity*>& neighbors);
        bool intersects(PositionComponent tl1, PositionComponent br1, PositionComponent tl2, PositionComponent br2);
        bool inCircle(PositionComponent pos, PositionComponent center, float radius);
};
