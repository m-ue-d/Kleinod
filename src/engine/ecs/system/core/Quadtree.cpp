//
// Created by fabia on 26.09.2023.
//

#include "Quadtree.h"
#include <cmath>

Quadtree::Quadtree() : node(nullptr), topLeft(PositionComponent(0,0,0)),
botRight(PositionComponent(0,0,0)), nw(nullptr), no(nullptr), sw(nullptr), so(nullptr){}

Quadtree::Quadtree(const PositionComponent& topL, const PositionComponent& botR) : node(nullptr),
topLeft(topL),botRight(botR), nw(nullptr), no(nullptr), sw(nullptr), so(nullptr){}

//Description: checks if the desired PositionComponent is inside the Quadtrees bounds (area and layer)
bool Quadtree::inBounds(const PositionComponent& p) {
    return (p.getX() >= topLeft.getX() && p.getX() <= botRight.getX() && p.getY() >= topLeft.getY() && p.getY() <= botRight.getY()
    && (p.getZ() == topLeft.getZ() || p.getZ() == botRight.getZ()));
}

//Description: inserts the desired node into the Quadtree
void Quadtree::put(Entity* n) {
    //check if the node is relevant for the quadtree
    if(n == nullptr || !inBounds(n->position))
        return;

    //check if the quad is already at the smallest area possible (unit area quad)
    if (botRight.getX() - topLeft.getY() <= 1 && botRight.getY() - topLeft.getY() <= 1) {
        if(node == nullptr)
            node = n;
        return;
    }

    if ((topLeft.getX() + botRight.getX()) / 2 >= node->position.getX()) {
        //indicates nw
        if ((topLeft.getY() + botRight.getY()) / 2 >= node->position.getY()) {
            if (nw == nullptr)
                nw = new Quadtree(
                        PositionComponent(topLeft.getX(), topLeft.getY()),
                        PositionComponent((topLeft.getX() + botRight.getX()) / 2,
                              (topLeft.getY() + botRight.getY()) / 2));
            nw->put(node);
        }

        //indicates sw
        else {
            if (sw == nullptr)
                sw = new Quadtree(
                        PositionComponent(topLeft.getX(),
                              (topLeft.getY() + botRight.getY()) / 2),
                        PositionComponent((topLeft.getX() + botRight.getX()) / 2,
                              botRight.getY()));
            sw->put(node);
        }
    }
    else {
        //indicates no
        if ((topLeft.getY() + botRight.getY()) / 2 >= node->position.getY()) {
            if (no == nullptr)
                no = new Quadtree(
                        PositionComponent((topLeft.getX() + botRight.getX()) / 2,
                              topLeft.getY()),
                        PositionComponent(botRight.getX(),
                              (topLeft.getY() + botRight.getY()) / 2));
            no->put(node);
        }

        //indicates so
        else {
            if (so == nullptr)
                so = new Quadtree(
                        PositionComponent((topLeft.getX() + botRight.getX()) / 2,
                              (topLeft.getY() + botRight.getY()) / 2),
                        PositionComponent(botRight.getX(), botRight.getY()));
            so->put(node);
        }
    }
}

void Quadtree::remove(const PositionComponent& pos) {
    //TODO: Implement
}


Entity* Quadtree::get(const PositionComponent& p) {
    //point isn't inside bounds
    if (!inBounds(p))
        return nullptr;

    //check if the quad is already at the smallest area possible (unit area quad)
    if (node != nullptr)
        return node;

    if ((topLeft.getX() + botRight.getX()) / 2 >= p.getX()) {
        //indicates nw
        if ((topLeft.getY() + botRight.getY()) / 2 >= p.getY()) {
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
        if ((topLeft.getY() + botRight.getY()) / 2 >= p.getY()) {
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

//TODO: maybe unused?
std::vector<Entity*> Quadtree::getNeighbors(const PositionComponent& p, double radius) const {
    std::vector<Entity*> neighbors;

    //calculate the bounds of the query area based on position p and radius
    PositionComponent queryTopLeft(p.getX() - radius, p.getY() - radius, p.getZ());
    PositionComponent queryBotRight(p.getX() + radius, p.getY() + radius, p.getZ());

    //check if query area intersects with Quadtree bounds
    if (!intersects(queryTopLeft, queryBotRight, topLeft, botRight))
        return neighbors; //no intersection, return empty vector

    getNeighborsRecursive(p, radius, neighbors);

    return neighbors;
}

void Quadtree::getNeighborsRecursive(PositionComponent p, double radius, std::vector<Entity*>& neighbors) const {
    //check if node intersects with the query area
    if (node != nullptr && inCircle(node->position, p, radius)) {
        neighbors.push_back(node);
    }

    //recursively search within child nodes
    if (nw != nullptr) nw->getNeighborsRecursive(p, radius, neighbors);
    if (no != nullptr) no->getNeighborsRecursive(p, radius, neighbors);
    if (sw != nullptr) sw->getNeighborsRecursive(p, radius, neighbors);
    if (so != nullptr) so->getNeighborsRecursive(p, radius, neighbors);
}

bool Quadtree::intersects(const PositionComponent& tl1, const PositionComponent& br1, const PositionComponent& tl2, const PositionComponent& br2) {
    //check if two rectangles defined by their top-left and bottom-right corners intersect
    return !(tl1.getX() > br2.getX() || br1.getX() < tl2.getX() || tl1.getY() > br2.getY() || br1.getY() < tl2.getY() || tl1.getZ() != tl2.getZ() || br1.getZ() != br2.getZ());
}

bool Quadtree::inCircle(const PositionComponent& pos, const PositionComponent& center, double radius) {
    //check if a position component is within a circular area defined by center and radius
    double distanceSquared = pow(pos.getX() - center.getX(), 2) + pow(pos.getY() - center.getY(), 2);
    return distanceSquared <= pow(radius, 2);
}