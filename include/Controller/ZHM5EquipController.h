#pragma once

#include "ZHM5BaseController.h"

class ZHM5EquipController : public ZHM5BaseController
{
public:
    TEntityRef<ZHitman5> m_pHitman;
    ZMorphemeNetworkInstance* m_pMrNetwork;
    float m_fGripBlendFraction;
    float m_fEquipAnimFraction;
    float m_fAnimDuration;
    float m_fAnimTime;
    bool m_bInitialized;
    bool m_bIsEquiping;
    bool m_bSetItemHandlingFlag;
    unsigned int m_nEquipAnimNodeID;
    unsigned int m_nCrouchEquipAnimNodeID;
};
