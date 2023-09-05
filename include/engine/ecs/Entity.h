//
// Created by Admin on 05.09.2023.
//

#ifndef KLEINOD_ENTITY_H
#define KLEINOD_ENTITY_H

struct Entity{
    public:
        int id;
        virtual ~Entity() = default;
        explicit Entity(int id);
};

#endif //KLEINOD_ENTITY_H
