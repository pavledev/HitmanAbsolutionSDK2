#pragma once

class ZKnowledge;

class SBehaviorTreeContext
{
public:
    ZKnowledge* m_pKnowledge;
    TMaxArray<TRefCountPtr<SKnownEntity>, 16> m_variables[192];

    enum UnkEnum : __int32
    {
        MAX_NUM_VARIABLES = 0x40
    };
};
