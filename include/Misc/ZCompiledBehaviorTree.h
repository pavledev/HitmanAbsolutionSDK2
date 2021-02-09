#pragma once

#include "SConditionScope.h"
#include "ZString.h"
#include "EBehaviorReturnCode.h"

class ZActiveBehavior;

class ZCompiledBehaviorTree
{
public:
    SConditionScope m_root;
    SBehaviorBase* m_pEnd;
    TArrayRef<ZString> m_sceneReferenceNames;

    class SInitializationResult
    {
    public:
        union
        {
            ZActiveBehavior* m_pSelectedBehavior;
            EBehaviorReturnCode m_eCommandResult;
        };

        enum UnkEnum : __int32
        {
            T_BEHAVIOR = 0x0,
            T_COMMAND = 0x1
        } m_type;
    };
};
