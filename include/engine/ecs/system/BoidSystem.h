//
// Created by Admin on 24.08.2023.
//

#ifndef KLEINOD_BOIDSYSTEM_H
#define KLEINOD_BOIDSYSTEM_H
#include <vector>
#include "Boid2D.h"
#include "System.h"

class BoidSystem : public System{
    public:
        void init(int amount);
        void handleBoids(...);
        explicit BoidSystem(int id);
    private:
        std::vector<Boid2D> boids;
        void AddVelocity(Boid2D boid2D, float x, float y);
};


#endif //KLEINOD_BOIDSYSTEM_H
