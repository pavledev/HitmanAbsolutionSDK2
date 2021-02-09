#pragma once

#include "ZSoundBlendContainerBase.h"
#include "ESoundCollisionType.h"
#include "ESOUND_3DROLLOFF_TYPE.h"
#include "TSharedValue.h"
#include "ZCurve.h"
#include "SFMODRolloffCurve.h"

class ZSoundBlendContainerPhysics : public ZSoundBlendContainerBase
{
public:
    ESoundCollisionType m_eCollisionType;
    float m_fMinDistance;
    float m_fMaxDistance;
    float m_fMinDistanceLoud;
    float m_fMaxDistanceLoud;
    ESOUND_3DROLLOFF_TYPE m_e3dRolloffType;
    TSharedValue<ZCurve> m_RolloffCurve;
    float m_aTempParams[10];
    TSharedValue<SFMODRolloffCurve> m_aCustomRolloffCurve;
};
