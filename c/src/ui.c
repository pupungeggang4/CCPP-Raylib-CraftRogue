#include "ui.h"

UITitle uiTitle = {
    {20, 20}, // textTitle
    {160, 160, 480, 80}, // buttonAdventure
    {180, 180}, // textAdventure
    {160, 240, 480, 80}, // buttonStart
    {180, 260}, // textStart
    {160, 320, 480, 80}, // buttonLoad
    {180, 340}, // textLoad
    {160, 400, 480, 80}, // buttonQuit
    {180, 420}, // textQuit
    {80, 160, 80, 80, 0, 80}, // arrow
};

UIField uiField = {

};

UIMenu uiMenu = {
    {160, 100, 480, 400}, // rect
    {180, 120}, // textPaused
    {160, 180, 480, 80}, // buttonResume
    {180, 200}, // textResume
    {160, 260, 480, 80}, // buttonGiveUp
    {180, 280}, // textGiveUp
    {160, 340, 480, 80}, // buttonSave
    {180, 360}, // textSave
    {160, 420, 480, 80}, // buttonQuit
    {180, 440}, // textQuit
    {80, 180, 80, 80, 0, 80}, // arrow
};
