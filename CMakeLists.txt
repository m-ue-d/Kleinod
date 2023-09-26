cmake_minimum_required(VERSION 3.21)
project(Kleinod)

set(CMAKE_CXX_STANDARD 23)

set(SDL_INCLUDE_DIR C:/Users/fabia/Desktop/DEV/libs/SDL2/include)
set(SDL_LIB_DIR C:/Users/fabia/Desktop/DEV/libs/SDL2/lib/x64)

include_directories(${SDL_INCLUDE_DIR})
link_directories(${SDL_LIB_DIR})


MACRO(HEADER_DIRECTORIES return_list)
    FILE(GLOB_RECURSE new_list *.h)
    SET(dir_list "")
    FOREACH(file_path ${new_list})
        GET_FILENAME_COMPONENT(dir_path ${file_path} PATH)
        SET(dir_list ${dir_list} ${dir_path})
    ENDFOREACH()
    LIST(REMOVE_DUPLICATES dir_list)
    SET(${return_list} ${dir_list})
ENDMACRO()
# TODO: Make Macro work =)

include_directories(
        include/engine/ecs/components/physics
        include/engine/ecs/components/physics/rigidbody
        include/engine/ecs/components/graphics
        include/engine/ecs/entities
        include/engine/ecs/system
        include/engine/ecs/system/core
        include/engine/ecs
        include/engine/editor
        include/engine/graphics)
set(SOURCES
        include/engine/ecs/entities/Boid2D.h
        include/engine/ecs/components/physics/rigidbody/RigidbodyComponent.h
        include/engine/ecs/components/physics/rigidbody/VelocityComponent.h
        src/engine/ecs/components/physics/rigidbody/RigidbodyComponent.cpp
        src/engine/ecs/components/physics/rigidbody/VelocityComponent.cpp
        src/engine/ecs/entities/Boid2D.cpp
        include/engine/ecs/system/BoidSystem.h
        src/engine/ecs/system/BoidSystem.cpp
        include/engine/ecs/Ecs.h
        include/engine/ecs/Entity.h
        src/engine/ecs/Entity.cpp
        src/engine/ecs/Ecs.cpp include/engine/ecs/System.h
        src/engine/ecs/System.cpp
        include/engine/ecs/components/graphics/SpriteComponent.h
        include/engine/ecs/components/physics/rigidbody/PositionComponent.h
        src/engine/ecs/components/physics/rigidbody/PositionComponent.cpp
        src/engine/ecs/components/graphics/SpriteComponent.cpp
        include/engine/graphics/SpriteMap.h
        src/engine/graphics/SpriteMap.cpp
        include/engine/ecs/system/core/PhysicsSystem.h
        include/engine/ecs/components/graphics/Camera.h
        src/engine/ecs/system/core/PhysicsSystem.cpp
        include/engine/ecs/system/core/quadtree.h
        src/engine/ecs/system/core/quadtree.cpp)

add_executable(Kleinod main.cpp ${SOURCES})

target_link_libraries(${PROJECT_NAME} SDL2main SDL2)