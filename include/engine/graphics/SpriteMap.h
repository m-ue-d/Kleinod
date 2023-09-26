//
// Created by Admin on 05.09.2023.
//
#pragma once

#include <unordered_map>
#include <string>
#include "SDL.h"

struct SpriteMap{
    public:
        std::unordered_map<int, SDL_Texture> *spriteMap;    //TODO: How the heck does SDL2 work? Should I use Texture or Surface here. Think about that MÜD...
        void addSprite(int id, const std::string& path);    // Adds and inits a sprite to use somewhere in the engine
};
