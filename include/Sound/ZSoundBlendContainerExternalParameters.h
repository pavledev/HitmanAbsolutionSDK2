#pragma once

#include "ZSoundBlendContainerBase.h"
#include "SSBCExternalParametersData.h"

class ZSoundBlendContainerExternalParameters : public ZSoundBlendContainerBase
{
public:
    bool m_bAutoDestruct;
    SSBCExternalParametersData* m_pData;
};
