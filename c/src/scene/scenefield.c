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

    drawTexture(asset.texture[T_MENU], uiField.buttonMenu);
    drawText("[I] Inventory", uiField.textTutorial, 20, BLACK);
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
    if (gameVar->menu) {
        if (utilPointInsideRectUI(pos, uiField.buttonMenu)) gameVar->menu = 0;
        sceneMenuMouseHandle(gameVar, pos, button);
    } else {
        if (utilPointInsideRectUI(pos, uiField.buttonMenu)) gameVar->menu = 1;
    }
}

