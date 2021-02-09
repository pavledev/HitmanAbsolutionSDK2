#pragma once

#include "ZMorphemeNetworkInstance.h"
#include "IMorphemeEntity.h"

class ZMovementAnimNode
{
public:
    ZMorphemeNetworkInstance* m_pMorphemeNetwork;
    unsigned int m_iNodeId;
    unsigned int m_iParentNodeId;

    virtual ~ZMovementAnimNode();
    virtual void Init(ZMorphemeNetworkInstance*, ZString);
    virtual void Init(IMorphemeEntity*, ZString);
    virtual void Init(ZMorphemeNetworkInstance*, unsigned int);
    virtual void Init(IMorphemeEntity*, unsigned int);
};
