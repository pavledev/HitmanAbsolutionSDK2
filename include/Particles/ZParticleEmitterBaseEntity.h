#pragma once

#include "ZSpatialEntity.h"
#include "IParticleEmitterEntity.h"
#include "ZResourcePtr.h"
#include "SParticleBlockHeader.h"
#include "ZParticleControllerEntity.h"
#include "TSharedPointer.h"
#include "ZEntitySingleton.h"

class ZParticleEmitterBaseEntity : public ZSpatialEntity, public IParticleEmitterEntity
{
public:
    float m_fSpeedMin;
    float m_fSpeedMax;
    float m_fInnerConeAngle;
    float m_fOuterConeAngle;
    ZResourcePtr m_pParticleControllerResource;
    ZEntityRef m_ParticleController;
    bool m_bEnabled;
    bool m_bEmitterSpaceParticles;
    __int8 m_bActivated : 1;
    __int8 m_bPositionPrevIsFoobar : 1;
    __int8 m_bHasVelocityConstants : 1;
    __int8 m_bEnabledRT : 1;
    __int8 m_bHasBeenEnabledRT : 1;
    __int8 m_bLulling : 1;
    __int8 m_bUsingControllerEntityRef : 1;
    __int8 m_bControllerResourceIsBad : 1;
    __int8 m_bIsStreamedIn : 1;
    float m_fEmissionTimeSeconds;
    float m_fParticlesPerSecond;
    float m_fParticlesPerSecondMax;
    float m_fFixedEmissionCount;
    float m_fVelocityContributionFactor;
    ZEntityRef m_TriggerBox;
    float m_fEmissionCameraProximity;
    SParticleBlockHeader* m_pBlockList;
    SVector3 m_vPositionPrev;
    unsigned int m_nShaderMask;
    float m_fEmissionTimeLeft;
    float m_fEmissionTimeFraction;
    float m_fEmissionCntLeft;
    int m_nESEntry;
    ZParticleControllerEntity* m_pParticleController;
    TSharedPointer<ZEntitySingleton> m_ParticleControllerSingletonPtr;
};
