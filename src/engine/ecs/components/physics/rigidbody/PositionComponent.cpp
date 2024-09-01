//
// Created by Admin on 05.09.2023.
//

#include "PositionComponent.h"

PositionComponent::PositionComponent(double x, double y, int z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

PositionComponent::PositionComponent(double x, double y) {
    this->x = x;
    this->y = y;
    this->z = 0;
}

PositionComponent::~PositionComponent() = default;
