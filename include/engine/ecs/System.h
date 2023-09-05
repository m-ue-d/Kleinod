//
// Created by Admin on 05.09.2023.
//

#ifndef KLEINOD_SYSTEM_H
#define KLEINOD_SYSTEM_H

struct System{
public:
    int id;
    virtual ~System() = default;
    explicit System(int id);
};

#endif //KLEINOD_SYSTEM_H
