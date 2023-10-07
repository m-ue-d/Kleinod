//
// Created by fabia on 26.09.2023.
//

#pragma once
#include "PositionComponent.h"
#include "Entity.h"

// The object, that is stored inside the tree
struct Node{
    PositionComponent pos;
    Entity* entity;
    explicit Node(PositionComponent p, Entity* e);
};

struct Quadtree{    //TODO-Future: Maybe test the quadtree by visually representing it's structure as a test-function!
    //boundary
    PositionComponent topLeft;
    PositionComponent botRight;

    //Node
    Node* node;

    //Quads
    Quadtree* nw;
    Quadtree* no;
    Quadtree* sw;
    Quadtree* so;
    public:
        Quadtree();
        Quadtree(PositionComponent topL, PositionComponent botR);
        void insert(Node *n);
        Node* search(PositionComponent p);
        bool inBoundary(PositionComponent p);
};