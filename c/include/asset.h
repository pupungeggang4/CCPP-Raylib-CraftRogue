#ifndef ASSET_H
#define ASSET_H

#include "includes.h"

struct Asset {
    Texture2D texture[100];
};

extern Asset asset;

void assetLoad();
void assetDispose();

#endif
