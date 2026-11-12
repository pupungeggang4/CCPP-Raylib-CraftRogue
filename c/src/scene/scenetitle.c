#include "scene.h"

#include "asset.h"
#include "ui.h"
#include "util.h"
#include "render.h"
#include "gamevar.h"

void sceneTitleReady(GameVar* gameVar) {
    gameVar->selectedTitle = 0;
}

void sceneTitleUpdate(GameVar* gameVar) {

}

void sceneTitleRender(GameVar* gameVar) {
    drawText("Planterguy Adventure", uiTitle.textTitle, 20, BLACK);
    drawRect(uiTitle.buttonAdventure, YELLOW);
    drawText("Adventue Mode", uiTitle.textAdventure, 20, BLACK);
    drawRect(uiTitle.buttonSurvival, PINK);
    drawText("Survival Mode", uiTitle.textSurvival, 20, BLACK);
    drawRect(uiTitle.buttonLoad, GRAY);
    drawText("Load Game", uiTitle.textLoad, 20, BLACK);
    drawRect(uiTitle.buttonQuit, YELLOW);
    drawText("Quit Game", uiTitle.textQuit, 20, BLACK);

    int pos[2] = {uiTitle.arrow[0], uiTitle.arrow[1] + uiTitle.arrow[5] * gameVar->selectedTitle};
    drawTexture(asset.texture[T_ARROW], pos);
}

void sceneTitleKeyHandle(GameVar* gameVar) {
    if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) gameVar->selectedTitle = (gameVar->selectedTitle + 3) % 4;
    else if (IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN)) gameVar->selectedTitle = (gameVar->selectedTitle + 1) % 4;
    else if (IsKeyPressed(KEY_ENTER)) {
        if (gameVar->selectedTitle == 0) gameVar->sceneNext = SELECT;
        else if (gameVar->selectedTitle == 1) gameVar->sceneNext = FIELD;
        else if (gameVar->selectedTitle == 3) gameVar->running = 0;
    }
}

void sceneTitleMouseHandle(GameVar* gameVar, Vector2 pos, int button) {
    if (button == LEFT) {
        if (utilPointInsideRectUI(pos, uiTitle.buttonAdventure)) gameVar->sceneNext = SELECT;
        if (utilPointInsideRectUI(pos, uiTitle.buttonSurvival)) gameVar->sceneNext = FIELD;
        if (utilPointInsideRectUI(pos, uiTitle.buttonQuit)) gameVar->running = 0;
    }
}

