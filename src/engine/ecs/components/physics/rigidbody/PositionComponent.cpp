//
// Created by Admin on 05.09.2023.
//

#include "PositionComponent.h"

PositionComponent::PositionComponent(float x, float y, int z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

PositionComponent::PositionComponent(float x, float y) {
    this->x = x;
    this->y = y;
    this->z = 0;
}

PositionComponent::~PositionComponent() = default;
