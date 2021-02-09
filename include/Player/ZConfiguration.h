#pragma once

#include "ZSimpleModuleBase.h"

class ZConfiguration
{
public:
    bool m_bUseGameController;
    bool m_bDefaultInvertVertical;
    bool m_bDefaultInvertHorizontal;
    bool m_bFastTargetSelection;
    bool m_bAutoInsertHM;
    bool m_bMouseInvertVertical;
    bool m_bMouseInvertHorizontal;
    ZSimpleModuleBase* m_pModuleBase;
};
