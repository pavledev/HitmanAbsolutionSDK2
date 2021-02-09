#pragma once

#include "STurnAnim.h"
#include "ZMorphemeNetworkInstance.h"

class ZHM5LocomotionTurnAnimDatabase
{
public:
    STurnAnim m_anTurnAnims[48];
    int m_nNumAnims;
    unsigned int m_nRootNodeId;
    ZMorphemeNetworkInstance* m_pNetwork;
};
