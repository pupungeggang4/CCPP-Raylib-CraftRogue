#ifndef INCLUDES_H
#define INCLUDES_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <raylib.h>
#include <raymath.h>

enum SceneName {TITLE, SELECT, FIELD};
enum State {NORMAL, INVENTORY, SELECT_FILE, SELECT_CHARACTER};
enum Direction {LEFT, RIGHT, UP, DOWN};
enum TextureIndex {T_ARROW};

typedef struct Asset Asset;
typedef struct GameVar GameVar;
typedef struct UITitle UITitle;
typedef struct UIField UIField;
typedef struct UIMenu UIMenu;

#endif
