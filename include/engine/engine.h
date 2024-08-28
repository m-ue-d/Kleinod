//
// Created by Admin on 28.08.2024.
//

#pragma once

class Engine {
    public:
        static Engine &shared_instance() {static Engine engine; return engine;}
        void init();

        ~Engine();
    private:
        Engine();
};