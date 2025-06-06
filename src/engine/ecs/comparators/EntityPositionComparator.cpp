//
// Created by Admin on 07.06.2025.
//

#include "EntityPositionComparator.h"

EntityPositionComparator::EntityPositionComparator(const PositionComponent& pos)
        : positionComponent(pos) {}

bool EntityPositionComparator::operator()(Entity *element) const {
    return element->position == positionComponent;
}
