//
// Created by Admin on 05.09.2023.
//

#pragma once
#include "PositionComponent.h"

struct Entity{
    public:
        int id;
        PositionComponent position;
        virtual ~Entity() = default;
        explicit Entity(int id);
        Entity(int id,PositionComponent p);
};

struct EntityComparator {
    int id;

    bool operator()(const Entity& element) const {
        return element.id == id;
    }
};