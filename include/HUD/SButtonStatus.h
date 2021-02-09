#pragma once

#include "EButtonDisplay.h"
#include "EControllerButton.h"
#include "EButtonState.h"
#include "GFxValue.h"
#include "ZString.h"

class SButtonStatus
{
public:
    EButtonDisplay eButtonDisplay;
    EControllerButton eButton;
    EButtonState state;
    bool dirty;
    bool fixed;
    bool enabled;
    bool activated;
    GFxValue mc;
    ZString text;
    float x;
    float y;
    float z;
    float scale;
    float width;
    float delta;
    float buttonValue;
    float totalTime;
    float currentTime;
};
