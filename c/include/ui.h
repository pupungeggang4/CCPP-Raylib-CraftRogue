#ifndef UI_H
#define UI_H

#include "includes.h"

struct UITitle {
    int textTitle[4];
    int buttonAdventure[4];
    int textAdventure[4];
    int buttonSurvival[4];
    int textSurvival[4];
    int buttonLoad[4];
    int textLoad[4];
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
