#include "scene.h"

#include "gamevar.h"

void sceneChange(GameVar* gameVar, int scene) {
    gameVar->scene = scene;
    if (scene == TITLE) sceneTitleReady(gameVar);
}
