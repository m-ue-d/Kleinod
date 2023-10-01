//
// Created by fabia on 26.09.2023.
//

#pragma once
#include "PositionComponent.h"
#include "Entity.h"

// The object, that is stored inside the tree
struct Node{
    PositionComponent* pos;
    Entity* entity;
    explicit Node(PositionComponent* _pos);
};

struct Quadtree{
    //TODO implement
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
        void insert(Node*);
        Node* search(PositionComponent);
        bool inBoundary(PositionComponent);
};