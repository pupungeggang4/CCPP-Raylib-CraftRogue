#ifndef GAME_H
#define GAME_H

#include "includes.h"

void gameInit(GameVar*);
void gameLoop(GameVar*);
void gameInputHandle(GameVar*);
void gameEnd(GameVar*);

#endif
