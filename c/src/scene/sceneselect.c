#include "scene.h"

#include "asset.h"
#include "ui.h"
#include "util.h"
#include "render.h"
#include "gamevar.h"

void sceneSelectReady(GameVar* gameVar) {
    gameVar->state = SELECT_WORLD;
}

void sceneSelectUpdate(GameVar* gameVar) {

}

void sceneSelectRender(GameVar* gameVar) { 
    drawRect(uiSelect.buttonRect, YELLOW);
    if (gameVar->state == SELECT_WORLD) {
        drawText("Select World", uiSelect.textTitle, 20, BLACK);
        for (int i = 0; i < 5; i++) {
            int rect[4] = {
                uiSelect.buttons[0], uiSelect.buttons[1] + uiSelect.buttons[3] * i,
                uiSelect.buttons[4], uiSelect.buttons[5]
            };

            if (gameVar->savedWorld[i].valid) drawRect(rect, PINK);
            else drawRect(rect, GRAY);
        }
    } else if (gameVar->state == SELECT_CHARACTER) {
        drawText("Select Character", uiSelect.textTitle, 20, BLACK);
        for (int i = 0; i < 5; i++) {
            int rect[4] = {
                uiSelect.buttons[0], uiSelect.buttons[1] + uiSelect.buttons[3] * i,
                uiSelect.buttons[4], uiSelect.buttons[5]
            };

            if (gameVar->savedCharacter[i].valid) drawRect(rect, PINK);
            else drawRect(rect, GRAY);
        }
    }

    drawRect(uiSelect.buttonNew, YELLOW);
    drawRect(uiSelect.buttonDelete, YELLOW);

    drawTexture(asset.texture[T_BACK], uiSelect.buttonBack);
}

void sceneSelectKeyHandle(GameVar* gameVar) {
    if (IsKeyPressed(KEY_ESCAPE)) {
        if (gameVar->state == SELECT_WORLD) gameVar->sceneNext = TITLE;
        else if (gameVar->state == SELECT_CHARACTER) gameVar->state = SELECT_WORLD;
    }
}

void sceneSelectMouseHandle(GameVar* gameVar, Vector2 pos, int button) {
    if (button == LEFT) {
        if (utilPointInsideRectUI(pos, uiSelect.buttonBack)) {
            if (gameVar->state == SELECT_WORLD) gameVar->sceneNext = TITLE;
            else if (gameVar->state == SELECT_CHARACTER) gameVar->state = SELECT_WORLD;
        }
    }
}

