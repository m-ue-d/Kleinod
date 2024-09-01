//
// Created by Admin on 05.09.2023.
//

#include "BoidSystem.h"
#include <random>

BoidSystem::BoidSystem(int id) : System(id) {}

//iterates through Boids and applies the 3 flock rules and some biases
void BoidSystem::handleBoids(...) { //TODO: Make use of variable length method to include multiple biases
    //separation

    //alignment

    //cohesion

    //additional Biases
}

//creates {amount} boids with a random position and 0 velocity
void BoidSystem::init(int amount) {
    double x{};
    double y{};
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(1.0, 10.0);
    for (int i = 0; i < amount; i++) {
        x= dist(mt);
        y= dist(mt);
        auto *boid = new Boid2D(0, x, y,0);
        boids.push_back(boid);
    }
}

void BoidSystem::initValues(double velocityModifier, double separationModifier, double alignmentModifier, double cohesionModifier){
    this->velocityMod = velocityModifier;
    this->separationMod = separationModifier;
    this->alignmentMod = alignmentModifier;
    this->cohesionMod = cohesionModifier;
}


//Boid2D functions
void BoidSystem::addVelocity(int boid2Did, double x, double y)
{
    this->boids[boid2Did]->rigidbody.velocity.x += x;
    this->boids[boid2Did]->rigidbody.velocity.x += x;
}

void BoidSystem::setViewRange(int boid2Did, double range) {
    this->boids[boid2Did]->viewRange = range;
}

void BoidSystem::setNeighborRange(int boid2Did, double range) {
    this->boids[boid2Did]->neighborRange = range;
}
