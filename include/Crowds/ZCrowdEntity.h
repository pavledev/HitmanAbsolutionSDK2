#pragma once

#include "ZRenderableEntity.h"
#include "IRenderGraphNodeProducer.h"
#include "IBoxVolumeEntity.h"
#include "ZSphereVolumeEntity.h"
#include "ZCrowdActorGroupEntity.h"
#include "ZCrowdDebris.h"
#include "ZCrowdMap.h"
#include "ECrowdFlowCandidates.h"
#include "ECrowdFlowUsage.h"
#include "ZCrowdTeleportEntity.h"
#include "SColorRGB.h"
#include "SCrowdCullingContext.h"
#include "ZCrowdCellMap.h"
#include "ZCrowdActorCore.h"
#include "ZCrowdActorSensorInput.h"
#include "SCrowdActorSensor.h"
#include "ZCrowdActor.h"
#include "ZCrowdRegion.h"
#include "ZCrowdAIPool.h"
#include "SCullResult.h"

class ZCrowdAnimationState;
class ZManualActorEntity;

class alignas(16) ZCrowdEntity : public ZRenderableEntity, public IRenderGraphNodeProducer
{
public:
    int m_nRandSeed;
    SVector3 m_vGlobalSize;
    float m_nGridCellSize;
    float m_nGridGeneratorOffset;
    TArray<TEntityRef<IBoxVolumeEntity>> m_aCrowdExclusionBoxes;
    TArray<TEntityRef<ZSphereVolumeEntity>> m_aCrowdExclusionSpheres;
    TArray<TEntityRef<IBoxVolumeEntity>> m_aCrowdPanicOnlyBoxes;
    TArray<TEntityRef<ZCrowdActorGroupEntity>> m_aCrowdGroupBoxes;
    bool m_bUseCrowdCameraProfile;
    bool m_bAllowCC;
    bool m_bAllowHumanShield;
    bool m_bAllowAICrowdShooting;
    bool m_bAllowFastWalk;
    bool m_bAllowRun;
    float m_nAllowRunRadius;
    bool m_bCrowdAffectNPCs;
    bool m_bDoHighLODSeparation;
    unsigned int m_nSeparationMaxLOD;
    unsigned int m_nAnimationBlendMaxLOD;
    bool m_bSmoothenExitFlows;
    float m_nPanicedActorRemoveFactor;
    float m_nPanicedActorExitFactor;
    float m_nPanicDebrisFactor;
    float m_nPanicDebrisTime;
    TArray<TEntityRef<ZCrowdDebris>> m_aPanicDebrisResources;
    TEntityRef<ZSpatialEntity> m_pPanicDebrisEntity;
    TSharedPointer<ZEntitySingleton> m_pPanicDebrisSingleton;
    unsigned int m_nPanicDebrisActivatePinID;
    float m_nAccumulatedDebrisTime;
    float m_nPanicDebrisTimer;
    TResourcePtr<ZCrowdMap> m_pCrowdMapResource;
    unsigned int m_nCrowdSize;
    unsigned int m_nReusableCores;
    float m_nMinSeparationDist;
    float m_nCrowdActorRadius;
    float m_nCrowdIdleRate;
    bool m_bAllowRandomStateChanges;
    TArray<TEntityRef<ZCrowdActorEntity>> m_aActorTemplates;
    TArray<TEntityRef<ZManualActorEntity>> m_aManuallyPlacedActors;
    unsigned int m_nAIPoolSize;
    TResourcePtr<IEntityFactory> m_pAIEntityFactory;
    ECrowdFlowCandidates m_eFlowCandidates;
    ECrowdFlowUsage m_eAmbientFlowUsage;
    TArray<TEntityRef<IBoxVolumeEntity>> m_aFlowBoxes;
    TArray<TEntityRef<IBoxVolumeEntity>> m_aFlowBoxesTwoWay;
    TArray<TEntityRef<ZCrowdTeleportEntity>> m_aCrowdTeleports;
    TArray<TEntityRef<ZSphereVolumeEntity>> m_aCrowdAvoidRegions;
    float m_nMaxCrowdRenderDist;
    unsigned int m_nMaxNumVisibleCharacters;
    float m_nCrowdLODDist1;
    unsigned int m_nCrowdLODCount1;
    float m_nCrowdLODDist2;
    unsigned int m_nCrowdLODCount2;
    float m_nCrowdLODDist3;
    unsigned int m_nCrowdLODCount3;
    SColorRGB m_HighlightColor;
    float m_nHighlightPower;
    float m_nHighlightFadeSpeed;
    bool m_bSpawnManualActorsOnly;
    bool m_bDisableActorMeshes;
    unsigned int m_nDebugMaxLOD;
    unsigned int m_nDebugFlowChannel;
    bool m_bDrawDebug;
    bool m_bDrawGridDebug;
    bool m_bDrawActorsDebug;
    bool m_bDrawBehaviorDebug;
    bool m_bDrawRegionDebug;
    bool m_bDrawFlowDebug;
    bool m_bLookatDebug;
    bool m_bWarzoneDebug;
    ZResourcePtr m_pGizmo;
    SVector4 m_vCrowdspaceToLocalSpaceOffset;
    ZCrowdMap* m_pCrowdMapPtr;
    SVector4 m_vWarzoneOrigin;
    int m_nMapDataDirtyCounter;
    bool m_bInitializedForSimulation;
    bool m_bThinkFlag;
    bool m_bIgnoreTimeMultiplier;
    unsigned int m_nCurrentThinkers;
    unsigned int m_nCurrentCulledAnim;
    unsigned int m_nCurrentRegions;
    unsigned int m_nCurrentCulledIntegration;
    SCrowdCullingContext m_sNextCullingContext;
    ZCrowdCellMap m_CellMap;
    ZCrowdActorCore* m_pActorCores;
    ZCrowdActorSensorInput* m_pActorSensorsInput;
    SCrowdActorSensor* m_pActorSensors;
    unsigned __int16 m_nextFreeReusableCore;
    TArray<TEntityRef<ZCrowdActor>> m_pActors;
    ZCrowdActorCore* m_pHitmanObstacle;
    unsigned int m_nCrowdIndex;
    TFixedArray<ZCrowdRegion, 256> m_aCrowdRegions;
    int* m_pAvoidRegionIDs;
    TArray<unsigned short> m_aHighlightedActors;
    bool m_bCrowdIsAmbient;
    bool m_bCrowdShouldBeAmbient;
    float m_nAccumulatedRemoveTime;
    float m_nPanicExitCount;
    ZCrowdAIPool* m_pAIPool;
    unsigned int m_nPrimitiveChangeCounter;
    unsigned __int8 m_nFinishedAnimStateIndex;
    ZCrowdAnimationState* m_aCrowdAnimationState[2];
    SMatrix m_WorldMatrix;
    bool m_bIsStreamedIn;
    bool m_bIsActivated;
    SCrowdCullingContext* m_pCrowdCullingContext;
    SCullResult* m_pCullFlagsWriteBuffer;

    virtual void OnTransformChanged(const ZEntityRef*, const SMatrix43*);
};
