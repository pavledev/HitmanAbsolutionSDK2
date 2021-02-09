#pragma once

#include "GFxValue.h"
#include "GFxMovieView.h"

struct Params
{
    GFxValue* pRetVal;
    GFxMovieView* pMovie;
    GFxValue* pThis;
    GFxValue* pArgsWithThisRef;
    GFxValue* pArgs;
    unsigned int ArgCount;
    void* pUserData;
};
