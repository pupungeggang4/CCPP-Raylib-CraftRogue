#ifndef GAMEVAR_H
#define GAMEVAR_H

#include "includes.h"

struct GameVar {
    Camera2D camera; float dt;
    int running;
    int scene; int sceneNext;
};

extern GameVar gameVar;

#endif
