cmake_minimum_required(VERSION 3.10)
project(SpaceInvaders)

include_directories(
    src/include
    /usr/include/freetype2
)

set(SOURCES
    src/main.c
    src/loop.c
    src/media.c
    src/display.c
    src/ship.c
    src/invaders.c
    src/distroy.c
    src/bullet.c
    src/clock.c
    src/score.c
    src/footer.c
    src/utils.c
    src/keyboard.c
)

add_executable(SpaceInvaders ${SOURCES})

target_link_libraries(SpaceInvaders
    X11
    Xft
    m
)

