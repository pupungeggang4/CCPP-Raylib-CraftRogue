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

    drawTexture(asset.texture[T_ADD], uiSelect.buttonNew);
    drawTexture(asset.texture[T_DELETE], uiSelect.buttonDelete);
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

        if (gameVar->state == SELECT_WORLD) {
            for (int i = 0; i < 5; i++) {
                int rect[4] = {
                    uiSelect.buttons[0], uiSelect.buttons[1] + uiSelect.buttons[3] * i,
                    uiSelect.buttons[4], uiSelect.buttons[5]
                };

                if (utilPointInsideRectUI(pos, rect)) {
                    if (gameVar->savedWorld[i].valid) gameVar->state = SELECT_CHARACTER;
                }
            }

            if (utilPointInsideRectUI(pos, uiSelect.buttonNew)) {
                for (int i = 0; i < 5; i++) {
                    if (!gameVar->savedWorld[i].valid) {
                        gameVar->savedWorld[i].valid = 1;
                        break;
                    }
                }
            }
        } else if (gameVar->state == SELECT_CHARACTER) {
            for (int i = 0; i < 5; i++) {
                int rect[4] = {
                    uiSelect.buttons[0], uiSelect.buttons[1] + uiSelect.buttons[3] * i,
                    uiSelect.buttons[4], uiSelect.buttons[5]
                };

                if (utilPointInsideRectUI(pos, rect)) {
                    if (gameVar->savedCharacter[i].valid) gameVar->sceneNext = FIELD;
                }
            }

            if (utilPointInsideRectUI(pos, uiSelect.buttonNew)) {
                for (int i = 0; i < 5; i++) {
                    if (!gameVar->savedCharacter[i].valid) {
                        gameVar->savedCharacter[i].valid = 1;
                        break;
                    }
                }
            }
        }
    }
}

