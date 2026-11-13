#include "asset.h"

Asset asset = {0};

void assetLoad() {
    asset.texture[T_ARROW] = LoadTexture("asset/image/arrow.png");
    asset.texture[T_BACK] = LoadTexture("asset/image/back.png");
    asset.texture[T_MENU] = LoadTexture("asset/image/menu.png");
    asset.texture[T_ADD] = LoadTexture("asset/image/add.png");
    asset.texture[T_DELETE] = LoadTexture("asset/image/delete.png");
}

void assetDispose() {
    for (int i = 0; i < 100; i++) {
        UnloadTexture(asset.texture[i]);
    }
}
