//
// Created by fabia on 26.09.2023.
//

#include "Quadtree.h"

//TODO: Implement
Node::Node(PositionComponent* _pos) {
    pos = _pos;
}

Quadtree::Quadtree() {
    topLeft = PositionComponent(0, 0,0);
    botRight = PositionComponent(0, 0,0);
    node = nullptr;
    nw = nullptr;
    no = nullptr;
    sw = nullptr;
    so = nullptr;

}

Quadtree::Quadtree(PositionComponent topL, PositionComponent botR) {
    topLeft = topL;
    botRight = botR;
    node = nullptr;
    nw = nullptr;
    no = nullptr;
    sw = nullptr;
    so = nullptr;
}

//Description: checks if the desired PositionComponent is inside the Quadtrees bounds (area and layer)
bool Quadtree::inBoundary(PositionComponent p) {
    return (p.x >= topLeft.x && p.x <= botRight.x && p.y >= topLeft.y && p.y <= botRight.y
    && (p.z == topLeft.z || p.z == botRight.z));
}
