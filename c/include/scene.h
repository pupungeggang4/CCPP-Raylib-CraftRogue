#ifndef SCENE_H
#define SCENE_H

#include "includes.h"

void sceneTitleReady(GameVar*);
void sceneTitleUpdate(GameVar*);
void sceneTitleRender(GameVar*);
void sceneTitleKeyHandle(GameVar*);
void sceneTitleMouseHandle(GameVar*, Vector2, int);

void sceneSelectReady(GameVar*);
void sceneSelectUpdate(GameVar*);
void sceneSelectRender(GameVar*);
void sceneSelectKeyHandle(GameVar*);
void sceneSelectMouseHandle(GameVar*, Vector2, int);

void sceneFieldReady(GameVar*);
void sceneFieldUpdate(GameVar*);
void sceneFieldRender(GameVar*);
void sceneFieldKeyHandle(GameVar*);
void sceneFieldMouseHandle(GameVar*, Vector2, int);

void sceneInventoryReady(GameVar*);
void sceneInventoryUpdate(GameVar*);
void sceneInventoryRender(GameVar*);
void sceneInventoryKeyHandle(GameVar*);
void sceneInventoryMouseHandle(GameVar*, Vector2, int);

void sceneMenuReady(GameVar*);
void sceneMenuUpdate(GameVar*);
void sceneMenuRender(GameVar*);
void sceneMenuKeyHandle(GameVar*);
void sceneMenuMouseHandle(GameVar*, Vector2, int);

#endif
