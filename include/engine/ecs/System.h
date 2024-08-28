//
// Created by Admin on 05.09.2023.
//

#pragma once

struct System{
    public:
        int id;
        virtual ~System() = default;
        explicit System(int id);
};

struct SystemComparator {
    int id;

    bool operator()(const System& element) const {
        return element.id == id;
    }
};