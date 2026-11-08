#ifndef INCLUDES_H
#define INCLUDES_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <raylib.h>
#include <raymath.h>

enum SceneName {TITLE, SELECT, FIELD};
enum State {NORMAL, INVENTORY, SELECT_FILE, SELECT_CHARACTER};

typedef struct GameVar GameVar;
typedef struct UITitle UITitle;
typedef struct UIEdit UIEdit;
typedef struct UIRun UIRun;

#endif
