#pragma once

#include "ZMovementAnimNode.h"
#include "eMorphemeRequests.h"
#include "TEntityRef.h"
//#include "ZHitman5.h"

class ZHitman5;

class alignas(4) ZMovementAnimTransition
{
public:
    unsigned int m_iAnimParentNode;
    ZMovementAnimNode* m_pAnimDestinationNode;
    eMorphemeRequests m_iMorphemeRequest;
    TEntityRef<ZHitman5> m_pHitman;
};
