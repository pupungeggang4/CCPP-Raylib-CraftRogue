#ifndef INCLUDES_H
#define INCLUDES_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <raylib.h>
#include <raymath.h>

enum SceneName {TITLE, SELECT, FIELD};
enum State {NORMAL, INVENTORY, SELECT_WORLD, SELECT_CHARACTER, NEW_WORLD, NEW_CHARACTER};
enum Direction {LEFT, RIGHT, UP, DOWN};

typedef struct Asset Asset;
typedef struct GameVar GameVar;
typedef struct UITitle UITitle;
typedef struct UISelect UISelect;
typedef struct UIField UIField;
typedef struct UIMenu UIMenu;

#endif
