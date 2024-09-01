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
        void initValues(double velocityMod, double separationMod, double alignmentMod, double cohesionMod);
        explicit BoidSystem(int id);
    private:
        double velocityMod = 1.0f;
        double separationMod = 1.0f;
        double alignmentMod = 1.0f;
        double cohesionMod = 1.0f;
        std::vector<Boid2D*> boids;
        void addVelocity(int boid2Did, double x, double y);
        void setViewRange(int boid2Did, double range);
        void setNeighborRange(int boid2Did, double range);
};
