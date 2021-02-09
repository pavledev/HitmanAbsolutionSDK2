#pragma once

#include "ZEntityImpl.h"
#include "EParticleSpritePivotLocation.h"
#include "SColorRGB.h"
#include "ZParticleRenderEntityBase.h"
#include "ParticleControllerJobFeedback.h"
#include "TFixedArray.h"
#include "SCollidingParticle.h"
#include "TBlockArray.h"
#include "SParticleEmitterEntry.h"
#include "TBag.h"

class alignas(16) ZParticleControllerEntity : public ZEntityImpl, public IParticleControllerEntity
{
public:
    ZResourcePtr m_pParticleRenderResource;
    ZEntityRef m_ParticleRender;
    unsigned int m_nMaxNumParticles;
    float m_fParticleCollisionSizeFactor;
    float m_fMotionStretchFactor;
    EParticleSpritePivotLocation m_ePivotLocation;
    float m_fWindMultiplier;
    float m_fCameraFadeNearDistance;
    float m_fCameraFadeFarDistance;
    float m_fCameraFadeSizeFactor;
    float m_fTimeToLiveSecondsMin;
    float m_fTimeToLiveSecondsMax;
    float m_fRotationSpeedMin;
    float m_fRotationSpeedMax;
    float m_fInitialRotation;
    float m_fInitialRotationDeviation;
    SVector3 m_vUpVectorRangeStart;
    SVector3 m_vUpVectorRangeEnd;
    SColorRGB m_ParticleColorRangeStart;
    SColorRGB m_ParticleColorRangeEnd;
    float m_fParticleSizeMin;
    float m_fParticleSizeMax;
    float m_fArrayIndexMin;
    float m_fArrayIndexMax;
    bool m_bGlobalAttractorsEnabled;
    bool m_bSizeDependantFadeDistances;
    bool m_bRandomRotation;
    bool m_bEmitterSpaceInitialUpVector;
    bool m_bEmitFrozen;
    bool m_bRandomFlipU;
    bool m_bRandomFlipV;
    __int8 m_bSomeEmittersWereDisabled : 1;
    __int8 m_bUsingRenderEntityRef : 1;
    __int8 m_bRenderResourceIsBad : 1;
    __int8 m_bIsStreamedIn : 1;
    ZParticleRenderEntityBase* m_pParticleRender;
    TSharedPointer<ZEntitySingleton> m_ParticleRenderSingletonPtr;
    ParticleControllerJobFeedback* m_pFeedback;
    TFixedArray<SCollidingParticle, 8> m_CollisionsFeedback;
    TBlockArray<SParticleEmitterEntry> m_ParticleEmitters;
    TArray<ZParticleEmitterBaseEntity*> m_ParticleEmittersDisabled;
    TArray<SParticleBlockHeader*> m_RemovedParticleEmittersThisFrame;
    TBag<TEntityRef<IParticleModifierEntity>, TArray<TEntityRef<IParticleModifierEntity> > > m_ParticleModifiers;
    unsigned int m_nNumModifiers;
    TBag<TEntityRef<IParticleHeirEntity>, TArray<TEntityRef<IParticleHeirEntity> > > m_ParticleHeirs;
    TEntityRef<IParticleColliderEntity> m_ParticleCollider;
    int m_nDirty;
    unsigned int m_nConstSizeEmitterCnt;
    unsigned int m_nLastConstSize;
    unsigned int m_nLastModifierConstSize;
    unsigned int m_nLastEmitterConstSize;
    unsigned int m_nEmitterShaderMask;
    unsigned int m_nModifierShaderMask;
    void* m_pPreviousSimulationMemBuffer;
    unsigned int m_nNumDeadParticlesNeeded;
};
