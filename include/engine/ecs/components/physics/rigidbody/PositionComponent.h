//
// Created by Admin on 05.09.2023.
//

#ifndef KLEINOD_POSITIONCOMPONENT_H
#define KLEINOD_POSITIONCOMPONENT_H

struct PositionComponent {
    public:
        PositionComponent(float x, float y, int z);
        PositionComponent(float x, float y);
        ~PositionComponent();

        float getX() const { return x; }
        float getY() const { return y; }
        int getZ() const { return z; }

    private:
        float x;
        float y;
        int z;
};

#endif //KLEINOD_POSITIONCOMPONENT_H
