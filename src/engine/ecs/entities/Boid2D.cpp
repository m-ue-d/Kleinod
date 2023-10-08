//
// Created by Admin on 24.08.2023.
//

#include "Boid2D.h"
Boid2D::Boid2D(int id, float x, float y, int z)
 : Entity(id, {x,y,z}), rigidbody({0, {0, 0.01}}) {}
