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
        Quadtree(const PositionComponent& topL, const PositionComponent& botR);
        void put(Entity *n);
        void remove(const PositionComponent& pos);
        Entity* get(const PositionComponent& p);
        bool inBounds(const PositionComponent& p);
        std::vector<Entity*> getNeighbors(const PositionComponent& p, float radius) const;
        void getNeighborsRecursive(PositionComponent p, float radius, std::vector<Entity*>& neighbors) const;
        static bool intersects(const PositionComponent& tl1, const PositionComponent& br1, const PositionComponent& tl2, const PositionComponent& br2);
        static bool inCircle(const PositionComponent& pos, const PositionComponent& center, float radius);
};
