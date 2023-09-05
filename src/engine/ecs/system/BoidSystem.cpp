//
// Created by Admin on 05.09.2023.
//

#include "BoidSystem.h"
#include <random>

// Iterates through Boids and applies the 3 flock rules and some biases
void BoidSystem::handleBoids(...) { //TODO: Make use of variable length method to include multiple biases

}
// Creates {amount} boids with a random position and 0 velocity
void BoidSystem::init(int amount) {
    float x{};
    float y{};
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<float> dist(1.0, 10.0);
    for (int i = 0; i < amount; i++) {
        x= dist(mt);
        y= dist(mt);
        auto *boid = new Boid2D(0, x, y);
        boids.push_back(*boid);
    }
}


void BoidSystem::AddVelocity(Boid2D boid2D, float x, float y)
{
    boid2D.rigidbody.velocity.x += x;
    boid2D.rigidbody.velocity.y += y;
}

BoidSystem::BoidSystem(int id) : System(id) {}
