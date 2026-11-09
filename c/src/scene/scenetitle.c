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
}

void sceneTitleKeyHandle(GameVar* gameVar) {

}

void sceneTitleMouseHandle(GameVar* gameVar, Vector2 pos, int button) {

}

