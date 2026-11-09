#ifndef UI_H
#define UI_H

#include "includes.h"

struct UITitle {
    int textTitle[4];
    int buttonStart[4];
    int textStart[4];
    int buttonAdventure[4];
    int textAdventure[4];
    int buttonQuit[4];
    int textQuit[4];
};

struct UIField {

};

struct UIMenu {

};

extern UITitle uiTitle;
extern UIField uiEdit;
extern UIMenu uiMenu;

#endif
