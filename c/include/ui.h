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
    int arrow[6];
};

struct UISelect {
    int textTitle[4];
    int buttonBack[4];
    int buttonRect[4];
    int buttons[6];
    int textbutton[6];
    int buttonNew[4];
    int buttonDelete[4];
};

struct UIField {
    int textTutorial[4];
    int buttonMenu[4];
};

struct UIMenu {
    int rect[4];
    int textPaused[4];
    int buttonResume[4];
    int textResume[4];
    int buttonGiveUp[4];
    int textGiveUp[4];
    int buttonSave[4];
    int textSave[4];
    int buttonQuit[4];
    int textQuit[4];
    int arrow[6];
};

extern UITitle uiTitle;
extern UISelect uiSelect;
extern UIField uiField;
extern UIMenu uiMenu;

#endif
