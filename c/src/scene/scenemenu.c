#include "scene.h"

#include "asset.h"
#include "ui.h"
#include "util.h"
#include "render.h"
#include "gamevar.h"

void sceneMenuReady(GameVar* gameVar) {
    gameVar->selectedMenu = 0;
}

void sceneMenuUpdate(GameVar* gameVar) {

}

void sceneMenuRender(GameVar* gameVar) {
    drawRect(uiMenu.rect, YELLOW);
    drawText("Paused", uiMenu.textPaused, 20, BLACK);
    drawRect(uiMenu.buttonResume, PINK);
    drawText("Resume", uiMenu.textResume, 20, BLACK);
    drawRect(uiMenu.buttonGiveUp, YELLOW);
    drawText("Give Up", uiMenu.textGiveUp, 20, BLACK);
    drawRect(uiMenu.buttonSave, PINK);
    drawText("Save and Exit", uiMenu.textSave, 20, BLACK);
    drawRect(uiMenu.buttonQuit, YELLOW);
    drawText("Quit Game", uiMenu.textQuit, 20, BLACK);

    int pos[2] = {uiMenu.arrow[0], uiMenu.arrow[1] + uiMenu.arrow[3] * gameVar->selectedMenu};
    drawTexture(asset.texture[T_ARROW], pos);
}

void sceneMenuKeyHandle(GameVar* gameVar) {
    if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) gameVar->selectedMenu = (gameVar->selectedMenu + 3) % 4;
    else if (IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN)) gameVar->selectedMenu = (gameVar->selectedMenu + 1) % 4;
    else if (IsKeyPressed(KEY_ENTER)) {
        if (gameVar->selectedMenu == 0) gameVar->menu = 0;
        else if (gameVar->selectedMenu == 1) {
            gameVar->sceneNext = TITLE;
        } else if (gameVar->selectedMenu == 2) {
            gameVar->sceneNext = TITLE;
        } else if (gameVar->selectedMenu == 3) gameVar->running = 0;
    }
}

void sceneMenuMouseHandle(GameVar* gameVar, Vector2 pos, int button) {
    if (button == LEFT) {
        if (utilPointInsideRectUI(pos, uiMenu.buttonResume)) {
            gameVar->menu = 0;
        } else if (utilPointInsideRectUI(pos, uiMenu.buttonGiveUp)) {
            gameVar->sceneNext = TITLE;
        } else if (utilPointInsideRectUI(pos, uiMenu.buttonSave)) {
            gameVar->sceneNext = TITLE;
        } else if (utilPointInsideRectUI(pos, uiMenu.buttonQuit)) {
            gameVar->running = 0;
        }
    }
}
