#ifndef ASSET_H
#define ASSET_H

#include "includes.h"

enum TextureIndex {T_ARROW, T_BACK, T_MENU, T_ADD, T_DELETE};

struct Asset {
    Texture2D texture[100];
};

extern Asset asset;

void assetLoad();
void assetDispose();

#endif
