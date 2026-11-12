#include "asset.h"

Asset asset = {0};

void assetLoad() {
    asset.texture[T_ARROW] = LoadTexture("asset/image/arrow.png");
}

void assetDispose() {
    for (int i = 0; i < 100; i++) {
        UnloadTexture(asset.texture[i]);
    }
}
