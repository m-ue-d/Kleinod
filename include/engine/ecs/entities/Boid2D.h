//
// Created by Admin on 24.08.2023.
//

#ifndef KLEINOD_BOID2D_H
#define KLEINOD_BOID2D_H
#include "RigidbodyComponent.h"
#include "Entity.h"
#include "SpriteComponent.h"


class Boid2D : public Entity{
    public:
        RigidbodyComponent rigidbody;
        SpriteComponent sprite;
        Boid2D(int id, float x, float y);
};


#endif //KLEINOD_BOID2D_H
