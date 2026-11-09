#ifndef SCENE_H
#define SCENE_H

#include "includes.h"

void sceneTitleReady(GameVar*);
void sceneTitleUpdate(GameVar*);
void sceneTitleRender(GameVar*);
void sceneTitleKeyHandle(GameVar*);
void sceneTitleMouseHandle(GameVar*, Vector2, int);

#endif
