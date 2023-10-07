//
// Created by fabia on 26.09.2023.
//

#include "Quadtree.h"
#include <cmath>

//TODO: Implement. And test it!
Node::Node(PositionComponent p, Entity* e) : pos(p), entity(e) {}

Quadtree::Quadtree() : node(nullptr), topLeft(PositionComponent(0,0,0)),
botRight(PositionComponent(0,0,0)), nw(nullptr), no(nullptr), sw(nullptr), so(nullptr){}

Quadtree::Quadtree(PositionComponent topL, PositionComponent botR) : node(nullptr),
topLeft(topL),botRight(botR), nw(nullptr), no(nullptr), sw(nullptr), so(nullptr){}

//Description: checks if the desired PositionComponent is inside the Quadtrees bounds (area and layer)
bool Quadtree::inBoundary(PositionComponent p) {
    return (p.x >= topLeft.x && p.x <= botRight.x && p.y >= topLeft.y && p.y <= botRight.y
    && (p.z == topLeft.z || p.z == botRight.z));
}

//Description: inserts the desired node into the Quadtree
void Quadtree::insert(Node *n) {
    //check if the node is relevant for the quadtree
    if(n == nullptr || !inBoundary(n->pos))
        return;

    //check if the quad is already at the smallest area possible (unit area quad)
    if (botRight.x - topLeft.y <= 1 && botRight.y - topLeft.y <= 1) {
        if(node == nullptr)
            node = n;
        return;
    }


    //TODO: Tidy this code up?
    if ((topLeft.x + botRight.x) / 2 >= node->pos.x) {
        // Indicates nw
        if ((topLeft.y + botRight.y) / 2 >= node->pos.y) {
            if (nw == nullptr)
                nw = new Quadtree(
                        PositionComponent(topLeft.x, topLeft.y),
                        PositionComponent((topLeft.x + botRight.x) / 2,
                              (topLeft.y + botRight.y) / 2));
            nw->insert(node);
        }

        // Indicates sw
        else {
            if (sw == nullptr)
                sw = new Quadtree(
                        PositionComponent(topLeft.x,
                              (topLeft.y + botRight.y) / 2),
                        PositionComponent((topLeft.x + botRight.x) / 2,
                              botRight.y));
            sw->insert(node);
        }
    }
    else {
        // Indicates no
        if ((topLeft.y + botRight.y) / 2 >= node->pos.y) {
            if (no == nullptr)
                no = new Quadtree(
                        PositionComponent((topLeft.x + botRight.x) / 2,
                              topLeft.y),
                        PositionComponent(botRight.x,
                              (topLeft.y + botRight.y) / 2));
            no->insert(node);
        }

        // Indicates so
        else {
            if (so == nullptr)
                so = new Quadtree(
                        PositionComponent((topLeft.x + botRight.x) / 2,
                              (topLeft.y + botRight.y) / 2),
                        PositionComponent(botRight.x, botRight.y));
            so->insert(node);
        }
    }
}
