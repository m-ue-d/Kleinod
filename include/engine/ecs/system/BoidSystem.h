//
// Created by Admin on 24.08.2023.
//

#pragma once
#include <vector>
#include "Boid2D.h"
#include "System.h"

class BoidSystem : public System{
    public:
        void init(int amount);
        void handleBoids(...);
        void initValues(float velocityMod, float separationMod, float alignmentMod, float cohesionMod);
        explicit BoidSystem(int id);
    private:
        float velocityMod = 1.0f;
        float separationMod = 1.0f;
        float alignmentMod = 1.0f;
        float cohesionMod = 1.0f;
        std::vector<Boid2D*> boids;
        void addVelocity(int boid2Did, float x, float y);
        void setViewRange(int boid2Did, float range);
        void setNeighborRange(int boid2Did, float range);
};
