//
// Created by Admin on 06.06.2025.
//

#pragma once

#include "Entity.h"

struct EntityPositionComparator {
    explicit EntityPositionComparator(const PositionComponent& pos);

    bool operator()(Entity *element) const;

    private:
        PositionComponent positionComponent;
};