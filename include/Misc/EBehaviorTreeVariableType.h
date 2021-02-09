#pragma once

enum EBehaviorTreeVariableType : unsigned __int32
{
    BTVT_Invalid = 0xFFFFFFFF,
    BTVT_SceneReference = 0x0,
    BTVT_Contextual = 0x1,
    BTVT_Dynamic = 0x2,
    BTVT_NumTypes = 0x3
};
