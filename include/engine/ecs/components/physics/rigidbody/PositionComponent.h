//
// Created by Admin on 05.09.2023.
//

#ifndef KLEINOD_POSITIONCOMPONENT_H
#define KLEINOD_POSITIONCOMPONENT_H

struct PositionComponent {
    public:
        PositionComponent(double x, double y, int z);
        PositionComponent(double x, double y);
        ~PositionComponent();

        double getX() const { return x; }
        double getY() const { return y; }
        int getZ() const { return z; }

    private:
        double x;
        double y;
        int z;
};

#endif //KLEINOD_POSITIONCOMPONENT_H
