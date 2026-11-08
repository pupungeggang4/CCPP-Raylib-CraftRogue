#ifndef GAMEVAR_H
#define GAMEVAR_H

#include "includes.h"

struct GameVar {
    Camera2D camera;
    int running;
    int scene;
};

extern GameVar gameVar;

#endif
