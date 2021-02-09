#pragma once

#include "ZMap.h"

class ZMapEaseToState
{
public:
    float m_fLastOutput;
    float m_fLastInput;
    float m_fStartInput;
    float m_fStartOutput;
    bool m_bHighState;
    const ZMap* m_MapFunction;
};
