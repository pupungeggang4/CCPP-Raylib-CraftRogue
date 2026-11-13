#ifndef GAMEVAR_H
#define GAMEVAR_H

#include "includes.h"

struct SavedWorld {
    int valid;
};

struct SavedCharacter {
    int valid;
};

struct GameVar {
    Camera2D camera; float dt;
    int running;
    int scene; int sceneNext; int state; int menu;

    int selectedTitle; int selectedMenu;

    struct SavedWorld savedWorld[5];
    struct SavedCharacter savedCharacter[5];
};

extern GameVar gameVar;

#endif
