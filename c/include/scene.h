#ifndef SCENE_H
#define SCENE_H

#include "includes.h"
void sceneChange(GameVar*, int);

void sceneTitleReady(GameVar*);
void sceneTitleUpdate(GameVar*);
void sceneTitleRender(GameVar*);
void sceneTitleKeyHandle(GameVar*);
void sceneTitleMouseHandle(GameVar*, Vector2);

#endif
