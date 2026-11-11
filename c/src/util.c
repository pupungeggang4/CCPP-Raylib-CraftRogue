#include "util.h"

int utilPointInsideRectUI(Vector2 pos, int rect[4]) {
    return pos.x > rect[0] && pos.x < rect[0] + rect[2] && pos.y > rect[1] && pos.y < rect[1] + rect[3];
}
