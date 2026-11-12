#include "gamevar.h"

#include "asset.h"
#include "scene.h"
#include "game.h"

void gameInit(GameVar* gameVar) {
    float aspRatio = 0.75;
    SetConfigFlags(FLAG_VSYNC_HINT);
    int width = 800, height = 600;
    InitWindow(width, height, "Planterguy's Advneture");
    #ifndef __APPLE__
    int mWidth = GetMonitorWidth(0); int mHeight = GetMonitorHeight(0);
    if (mWidth * aspRatio > height) {
        height = (int)(mHeight * 0.8); width = (int)(height / aspRatio);
    } else {
        width = (int)(mWidth * 0.8); height = (int)(width * aspRatio);
    }
    SetWindowSize(width, height);
    SetWindowPosition((mWidth - width) / 2, (mHeight - height) / 2);
    #endif
    SetExitKey(KEY_NULL);

    Camera2D tempCamera = {0}; gameVar->camera = tempCamera;
    gameVar->running = 1;

    assetLoad();

    sceneTitleReady(gameVar);
}

void gameLoop(GameVar* gameVar) {
    gameVar->dt = GetFrameTime();
    gameVar->camera.zoom = GetRenderWidth() / 800.0f;

    gameInputHandle(gameVar);
    if (gameVar->scene == TITLE) sceneTitleUpdate(gameVar);
    else if (gameVar->scene == SELECT) sceneSelectUpdate(gameVar);
    else if (gameVar->scene == FIELD) sceneFieldUpdate(gameVar);

    BeginDrawing();
    BeginMode2D(gameVar->camera);
    ClearBackground(RAYWHITE); 
    if (gameVar->scene == TITLE) sceneTitleRender(gameVar);
    else if (gameVar->scene == SELECT) sceneSelectRender(gameVar);
    else if (gameVar->scene == FIELD) sceneFieldRender(gameVar);
    EndMode2D();
    EndDrawing();

    if (gameVar->sceneNext != -1) {
        gameVar->scene = gameVar->sceneNext;
        if (gameVar->scene == TITLE) sceneTitleReady(gameVar);
        else if (gameVar->scene == SELECT) sceneSelectReady(gameVar);
        else if (gameVar->scene == FIELD) sceneFieldReady(gameVar);
        gameVar->sceneNext = -1;
    }

    if (WindowShouldClose()) gameVar->running = 0;
}

void gameInputHandle(GameVar* gameVar) {
    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
        Vector2 pos = GetMousePosition();
        pos = Vector2Scale(pos, 1 / gameVar->camera.zoom);
        printf("(%.0f, %.0f)\n", pos.x, pos.y);
        if (gameVar->scene == TITLE) sceneTitleMouseHandle(gameVar, pos, LEFT);
        else if (gameVar->scene == SELECT) sceneSelectMouseHandle(gameVar, pos, LEFT);
        else if (gameVar->scene == FIELD) sceneFieldMouseHandle(gameVar, pos, LEFT);

    } else if (IsMouseButtonReleased(MOUSE_BUTTON_RIGHT)) {
        Vector2 pos = GetMousePosition();
        pos = Vector2Scale(pos, 1 / gameVar->camera.zoom);
        printf("(%.0f, %.0f)\n", pos.x, pos.y);
        if (gameVar->scene == TITLE) sceneTitleMouseHandle(gameVar, pos, RIGHT);
        else if (gameVar->scene == SELECT) sceneSelectMouseHandle(gameVar, pos, RIGHT);
        else if (gameVar->scene == FIELD) sceneFieldMouseHandle(gameVar, pos, RIGHT);
    }

    if (gameVar->scene == TITLE) sceneTitleKeyHandle(gameVar);
    else if (gameVar->scene == SELECT) sceneSelectKeyHandle(gameVar);
    else if (gameVar->scene == FIELD) sceneFieldKeyHandle(gameVar);
}

void gameEnd(GameVar* gameVar) {
    assetDispose();
    CloseWindow();
}
