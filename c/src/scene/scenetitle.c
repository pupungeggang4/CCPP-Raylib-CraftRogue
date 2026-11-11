#include "scene.h"

#include "ui.h"
#include "util.h"
#include "render.h"
#include "gamevar.h"

void sceneTitleReady(GameVar* gameVar) {

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
}

void sceneTitleKeyHandle(GameVar* gameVar) {

}

void sceneTitleMouseHandle(GameVar* gameVar, Vector2 pos, int button) {
    if (button == LEFT) {
        if (utilPointInsideRectUI(pos, uiTitle.buttonAdventure)) gameVar->sceneNext = SELECT;
        if (utilPointInsideRectUI(pos, uiTitle.buttonSurvival)) gameVar->sceneNext = FIELD;
        if (utilPointInsideRectUI(pos, uiTitle.buttonQuit)) gameVar->running = 0;
    }
}

