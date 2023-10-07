cmake_minimum_required(VERSION 3.21)
project(Kleinod)

find_package(SDL2 CONFIG REQUIRED)

set(CMAKE_CXX_STANDARD 23)

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
        include/engine/ecs/system/core/Quadtree.h
        src/engine/ecs/system/core/Quadtree.cpp
        include/engine/ecs/system/core/PositionSystem.h)

add_executable(Kleinod main.cpp ${SOURCES})

target_link_libraries(Kleinod
        PRIVATE
        SDL2::SDL2)

target_link_libraries(Kleinod
        PRIVATE
        $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
        $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
)