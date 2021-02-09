#pragma once

class alignas(4) ZMap
{
public:
    float m_fFirstHalf;
    __int8 m_bFlipInput : 1;
    __int8 m_bFlipOutput : 1;
    __int8 m_bMirror : 1;
    __int8 m_bAllowModifiers : 1;

    virtual ~ZMap();
    virtual float MapFunction(float);
};
