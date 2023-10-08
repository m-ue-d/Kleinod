//
// Created by fabia on 26.09.2023.
//

#include "Quadtree.h"
#include <cmath>

Quadtree::Quadtree() : node(nullptr), topLeft(PositionComponent(0,0,0)),
botRight(PositionComponent(0,0,0)), nw(nullptr), no(nullptr), sw(nullptr), so(nullptr){}

Quadtree::Quadtree(PositionComponent topL, PositionComponent botR) : node(nullptr),
topLeft(topL),botRight(botR), nw(nullptr), no(nullptr), sw(nullptr), so(nullptr){}

//Description: checks if the desired PositionComponent is inside the Quadtrees bounds (area and layer)
bool Quadtree::inBounds(PositionComponent p) {
    return (p.x >= topLeft.x && p.x <= botRight.x && p.y >= topLeft.y && p.y <= botRight.y
    && (p.z == topLeft.z || p.z == botRight.z));
}

//Description: inserts the desired node into the Quadtree
void Quadtree::put(Entity* n) {
    //check if the node is relevant for the quadtree
    if(n == nullptr || !inBounds(n->position))
        return;

    //check if the quad is already at the smallest area possible (unit area quad)
    if (botRight.x - topLeft.y <= 1 && botRight.y - topLeft.y <= 1) {
        if(node == nullptr)
            node = n;
        return;
    }

    if ((topLeft.x + botRight.x) / 2 >= node->position.x) {
        //indicates nw
        if ((topLeft.y + botRight.y) / 2 >= node->position.y) {
            if (nw == nullptr)
                nw = new Quadtree(
                        PositionComponent(topLeft.x, topLeft.y),
                        PositionComponent((topLeft.x + botRight.x) / 2,
                              (topLeft.y + botRight.y) / 2));
            nw->put(node);
        }

        //indicates sw
        else {
            if (sw == nullptr)
                sw = new Quadtree(
                        PositionComponent(topLeft.x,
                              (topLeft.y + botRight.y) / 2),
                        PositionComponent((topLeft.x + botRight.x) / 2,
                              botRight.y));
            sw->put(node);
        }
    }
    else {
        //indicates no
        if ((topLeft.y + botRight.y) / 2 >= node->position.y) {
            if (no == nullptr)
                no = new Quadtree(
                        PositionComponent((topLeft.x + botRight.x) / 2,
                              topLeft.y),
                        PositionComponent(botRight.x,
                              (topLeft.y + botRight.y) / 2));
            no->put(node);
        }

        //indicates so
        else {
            if (so == nullptr)
                so = new Quadtree(
                        PositionComponent((topLeft.x + botRight.x) / 2,
                              (topLeft.y + botRight.y) / 2),
                        PositionComponent(botRight.x, botRight.y));
            so->put(node);
        }
    }
}

Entity* Quadtree::get(PositionComponent p) {
    //point isn't inside bounds
    if (!inBounds(p))
        return nullptr;

    //check if the quad is already at the smallest area possible (unit area quad)
    if (node != nullptr)
        return node;

    if ((topLeft.x + botRight.x) / 2 >= p.x) {
        //indicates nw
        if ((topLeft.y + botRight.y) / 2 >= p.y) {
            if (nw == nullptr)
                return nullptr;
            return nw->get(p);
        }

            //indicates sw
        else {
            if (sw == nullptr)
                return nullptr;
            return sw->get(p);
        }
    }
    else {
        //indicates no
        if ((topLeft.y + botRight.y) / 2 >= p.y) {
            if (no == nullptr)
                return nullptr;
            return no->get(p);
        }

            //indicates so
        else {
            if (so == nullptr)
                return nullptr;
            return so->get(p);
        }
    }
}

std::vector<Entity *> Quadtree::getNeighbors(PositionComponent p, float radius) {
    //TODO: Implement



    return std::vector<Entity *>();
}
