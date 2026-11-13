#include "render.h"

void drawText(const char* text, int pos[4], int size, Color color) {
    DrawText(text, pos[0], pos[1], size, color);
}

void drawRect(int pos[4], Color color) {
    DrawRectangle(pos[0], pos[1], pos[2], pos[3], color);
}

void drawTexture(Texture2D texture, int pos[2]) {
    DrawTexture(texture, pos[0], pos[1], WHITE);
}
