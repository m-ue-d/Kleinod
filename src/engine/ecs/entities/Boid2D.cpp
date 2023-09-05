//
// Created by Admin on 24.08.2023.
//

#include "Boid2D.h"
Boid2D::Boid2D(int id, float x, float y) : Entity(id) {
    rigidbody = {0, {x, y}, {0, 0.01}};
    sprite = {0};
}
