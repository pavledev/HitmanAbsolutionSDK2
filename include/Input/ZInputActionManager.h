#pragma once

#include "IComponentInterface.h"
#include "ZActionMapTree.h"

class ZInputActionManager : public IComponentInterface
{
public:
    ZActionMapTree* m_pkRoot;
    ZActionMapTree* m_pkCurrentBlock;
    int m_iBindMem;
    bool m_bDebugKeys;
    bool m_bEnabled;
    bool m_bSpeedRepeat;
    bool m_JoinControllers;
    ZGameTime m_EventHorizonDelay;
};
