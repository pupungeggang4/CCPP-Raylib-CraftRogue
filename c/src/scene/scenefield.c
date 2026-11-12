#include "scene.h"

#include "asset.h"
#include "ui.h"
#include "util.h"
#include "render.h"
#include "gamevar.h"

void sceneFieldReady(GameVar* gameVar) {

}

void sceneFieldUpdate(GameVar* gameVar) {

}

void sceneFieldRender(GameVar* gameVar) {
    if (gameVar->menu) {
        sceneMenuRender(gameVar);
    }
}

void sceneFieldKeyHandle(GameVar* gameVar) {
    if (gameVar->menu) {
        if (IsKeyPressed(KEY_ESCAPE)) gameVar->menu = 0;
        sceneMenuKeyHandle(gameVar);
    } else {
        if (IsKeyPressed(KEY_ESCAPE)) gameVar->menu = 1;
    }
}

void sceneFieldMouseHandle(GameVar* gameVar, Vector2 pos, int button) {
}

