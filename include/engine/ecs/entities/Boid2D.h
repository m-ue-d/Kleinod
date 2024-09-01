//
// Created by Admin on 24.08.2023.
//

#pragma once
#include "RigidbodyComponent.h"
#include "Entity.h"
#include "SpriteComponent.h"


struct Boid2D : public Entity{
    public:
        double neighborRange = 1.0f;
        double viewRange = 10.0f;
        RigidbodyComponent rigidbody;
        SpriteComponent sprite = {0};
        Boid2D(int id, double x, double y, int z);
};
