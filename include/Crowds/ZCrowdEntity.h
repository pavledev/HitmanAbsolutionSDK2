#pragma once

#include "ZRenderableEntity.h"
#include "IRenderGraphNodeProducer.h"
#include "ECrowdFlowCandidates.h"
#include "ECrowdFlowUsage.h"
#include "SColorRGB.h"
#include "SCrowdCullingContext.h"
#include "ZCrowdCellMap.h"
#include "ECrowdActorType.h"
#include "CrowdRegionType.h"
#include "CrowdUtil.h"
#include "SComponentMapEntry.h"
#include "SMatrix.h"
#include "SVector3.h"
#include "SVector4.h"
#include "TArray.h"
#include "TEntityRef.h"
#include "TFixedArray.h"
#include "TResourcePtr.h"
#include "TSharedPointer.h"
#include "ZEntityRef.h"
#include "ZResourcePtr.h"
#include "ZVariantRef.h"
#include "float4.h"
#include "ZCrowdRegion.h"

class ZCrowdAnimationState;
class ZManualActorEntity;
class ZCrowdRagdollManager;
class ZRayQueryInput;
class ZRayQueryOutput;
struct SGameUpdateEvent;
class IBoxVolumeEntity;
class IEntityFactory;
class ZComponentCreateInfo;
class ZCrowdAIPool;
class ZCrowdActor;
class ZCrowdActorCore;
class ZCrowdActorEntity;
class ZCrowdActorGroupEntity;
class ZCrowdActorSensorInput;
class ZCrowdDebris;
class ZCrowdMap;
class ZCrowdTeleportEntity;
class ZEntitySingleton;
class ZRenderGraphNode;
class ZSpatialEntity;
class ZSphereVolumeEntity;
class ZString;
struct SCrowdActorSensor;
struct SCullResult;
struct SMatrix43;
struct STypeID;
template <class A, class B> class THashSet;
template <class T> class TDefaultHashSetPolicy;

class ZCrowdEntity : public ZRenderableEntity, public IRenderGraphNodeProducer
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

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
	unsigned short m_nextFreeReusableCore;
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
	unsigned char m_nFinishedAnimStateIndex;
	ZCrowdAnimationState* m_aCrowdAnimationState[2];
	SMatrix m_WorldMatrix;
	bool m_bIsStreamedIn;
	bool m_bIsActivated;
	SCrowdCullingContext* m_pCrowdCullingContext;
	SCullResult* m_pCullFlagsWriteBuffer;

	static SComponentMapEntry s_componentMap[0];
	static TArray<ZCrowdEntity*>* s_aAllCrowds;
	static unsigned int m_snGentlePushSignal;
	static unsigned int m_snGentlePush;
	static unsigned int m_snHardPushSignal;
	static unsigned int m_snHardPush;
	static unsigned int m_snHitmanPushSignal;
	static unsigned int m_snHitmanPush;
	static unsigned int m_snMalePushSignal;
	static unsigned int m_snMalePush;
	static unsigned int m_snFemalePushSignal;
	static unsigned int m_snFemalePush;
	static unsigned int m_snAccident;
	static unsigned int m_snAccidentAtPos;
	static unsigned int m_snSomeonePacified;
	static unsigned int m_snSomeonePacifiedAtPos;
	static unsigned int m_snSomeoneDied;
	static unsigned int m_snSomeoneDiedAtPos;
	static unsigned int m_snSomeoneScared;
	static unsigned int m_snSomeoneScaredAtPos;
	static unsigned int m_snShotFired;
	static unsigned int m_snShotFiredAtPos;
	static unsigned int m_snShotFiredIntoCrowd;
	static unsigned int m_snExplosionAtPos;
	static unsigned int m_snNPCAmbient;
	static unsigned int m_snNPCAmbientPos;
	static unsigned int m_snNPCAlerted;
	static unsigned int m_snNPCAlertedPos;
	static unsigned int m_snNPCCivilianAlerted;
	static unsigned int m_snNPCCivilianAlertedPos;
	static unsigned int m_snNPCScared;
	static unsigned int m_snNPCScaredPos;
	static unsigned int m_snNPCCivilianScared;
	static unsigned int m_snNPCCivilianScaredPos;
	static unsigned int m_snNPCDead;
	static unsigned int m_snNPCDeadPos;
	static ZCrowdRagdollManager* s_pCrowdRagdollManager;
	static unsigned int s_nNumActivatedCrowdEntities;

	~ZCrowdEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Activate(const ZString& sSubset) override;
	void Deactivate(const ZString& sSubset) override;
	void StreamIn() override;
	void StreamOut() override;
	bool IsStreamedIn() override;
	void GetStreamableIncludes(THashSet<ZEntityRef, TDefaultHashSetPolicy<ZEntityRef>>& streamableIncludes) const override;
	void Init() override;
	void CalculateBounds(float4& vMin, float4& vMax, const unsigned int nIncludeFlags, const unsigned int nExcludeFlags) override;
	virtual void OnTransformChanged(const ZEntityRef& entity, const SMatrix43& newValue);

	ZRenderGraphNode* CreateRenderGraphNode() override;

	ZCrowdEntity() = default;
	static void RegisterType();
	ZCrowdEntity(const ZCrowdEntity& __that);
	ZCrowdEntity(ZComponentCreateInfo& Info);
	float GetCrowdActorRadius() const;
	float GetCrowdActorDeadRadius() const;
	float GetCrowdActorDeadCollisionRadius() const;
	float GetCrowdBaseCharRadius() const;
	float GetCrowdBaseCharCollisionRadius() const;
	float GetMinSeparationDist() const;
	float GetCrowdIdleRate() const;
	unsigned int GetNumCharacterTemplates() const;
	TEntityRef<ZCrowdActorEntity> GetActorTemplate(unsigned int i) const;
	unsigned int GetCrowdSize() const;
	float GetCrowdRenderDist() const;
	unsigned int GetMaxNumVisibleCharacters() const;
	float4 GetLODDistances() const;
	unsigned int GetLODCount1() const;
	unsigned int GetLODCount2() const;
	unsigned int GetLODCount3() const;
	bool HasAllocatedActors() const;
	TEntityRef<ZCrowdActor> GetCrowdActor(int i) const;
	ZCrowdActorCore* GetCrowdActorCore(short i) const;
	unsigned int GetNumManualActors() const;
	bool FullyStreamedIn() const;
	bool IsActive() const;
	bool GetAllowCC() const;
	bool GetAllowHumanShield() const;
	bool GetAllowAICrowdShooting() const;
	bool IsCrowdAmbient() const;
	bool GetCrowdAffectNPCs() const;
	bool GetUseCrowdCameraProfile() const;
	bool GetDisableActorMeshRendering() const;
	bool GetAllowRunning() const;
	float GetAllowRunRadius() const;
	bool GetAllowFastWalk() const;
	unsigned int GetAnimationBlendMaxLOD() const;
	unsigned int GetNumCrowdCores() const;
	const ZCrowdMap* GetCrowdMap() const;
	bool IsWorldPosNearValidCrowdCell(const float4& vWorldPos, float nCheckRange);
	SMatrix GetCrowdSpaceToLocalSpaceMatrix() const;
	float4 GetCrowdSpaceToLocalSpaceOffset() const;
	bool IsCrowdSpacePositionWithinCrowdBox(const float4& vPosCrowdSpace) const;
	bool IsWorldSpacePositionWithinCrowdBox(const float4& vPosWorldSpace) const;
	unsigned int GetNumFlowChannels() const;
	float4 GetFlowVector(const float4& vLocalPos, unsigned int nFlowChannel) const;
	float4 GetFlowVector(TEntityRef<ZCrowdActor> pActor, unsigned int nFlowChannel) const;
	bool GetFlowTwoWay(const float4& vLocalPos, unsigned int nFlowChannel) const;
	bool GetFlowTwoWay(TEntityRef<ZCrowdActor> pActor, unsigned int nFlowChannel) const;
	unsigned short GetFlowCost(TEntityRef<ZCrowdActor> pActor, unsigned int nFlowChannel) const;
	void RemoveFromCrowd(ZCrowdActorCore* pObstacle);
	void UpdateCellLocation(ZCrowdActorCore* pObstacle, unsigned int nNewCellIndex);
	unsigned int UpdateCellLocation(ZCrowdActorCore* pObstacle, const float4& vNewPosition);
	void GetObstacles(const float4& vCrowdPos, float nRadius, TArray<ZCrowdActorCore*>* pResult, ZCrowdActorCore* pSelf);
	bool IsInTeleportOutZone(const ZCrowdActorCore& rCore) const;
	TEntityRef<ZCrowdTeleportEntity> GetTeleportEntity(const ZCrowdActorCore& pCore) const;
	float GetPanicExitCount() const;
	void AdjustPanicExitCount(float nCount);
	void SignalAccident(ZCrowdActorCore* pObstacle);
	void SignalSomeonePacified(ZCrowdActorCore* pObstacle);
	void SignalSomeoneDied(ZCrowdActorCore* pObstacle, unsigned int nDeathFlags);
	void SignalSomeoneScared(ZCrowdActorCore* pObstacle);
	void SignalShotFired(ZCrowdActorCore* pObstacle);
	void SignalShotFiredIntoCrowd(const SVector3& vShotWorldPos);
	void SignalExplosion(const SVector3& vExplosionPos);
	void SignalPush(ZCrowdActorCore* pPusher, ZCrowdActorCore* pPushTarget, bool bHardPush);
	void SignalNPCMood(ZCrowdActorCore* pNPCCore, CrowdUtil::ECrowdActorMood eMood, bool bIsCivilian);
	void EscalateToActionCrowd(const float4& vWarzoneOrigin);
	void UpdateWarzoneOrigin(const float4& vWarzoneOrigin);
	void SetIgnoreTimeMultiplier(bool bIgnoreTimeMultiplier);
	void MarkRenderDirty();
	unsigned int GetPrimitiveChangeCounter() const;
	const ZCrowdAnimationState& GetCrowdAnimationState() const;
	void ReceiveCullingContext(const SCrowdCullingContext& sCullingContext);
	ZCrowdRagdollManager* GetRagdollManager() const;
	ZCrowdAIPool* GetAIPool() const;
	bool CastRayAgainstActor(TEntityRef<ZCrowdActor> pCrowdActor, const ZRayQueryInput& sRayInput, ZRayQueryOutput* pOutput);
	TEntityRef<ZCrowdActor> CastRayAgainstCrowd(const ZRayQueryInput& sRayInput, ZRayQueryOutput* pOutput);
	static TEntityRef<ZCrowdActor> CastRayAgainstAllCrowds(const ZRayQueryInput& sRayInput, ZRayQueryOutput* pOutput);
	int AddRegionWorldSpace(CrowdRegionType eType, const float4& vCenterWorldSpace, float nDirection, float nRadius, unsigned int nAngle, float nTimeout, ZCrowdActorCore* pOwner);
	static ZCrowdRegion* GetCrowdRegion(int nRegionID);
	static void ReleaseClaimedRegion(int nRegionID, float nTimeout);
	void ClearCrowdHighlights();
	void AddHighlightedCharacter(unsigned short nActorIndex);
	const TArray<unsigned short>& GetHighlightedCharacters() const;
	const SColorRGB& GetHighlightColor() const;
	void SetHighlightColor(const SColorRGB& c);
	float GetHighlightPower() const;
	void SetHighlightPower(float p);
	float GetHighlightFadeSpeed() const;
	static ZCrowdActorCore* UpdateNonCrowdActorObstacle(ZCrowdActorCore* pObstacle, ECrowdActorType eType, const float4& vWorldPos, const float4& vWorldForward, const float4& vWorldVelocity);
	ZCrowdActorCore* GetHitmanObstacle() const;
	void SetHitmanObstacle(ZCrowdActorCore* pHitman);
	static TEntityRef<ZCrowdEntity> GetCrowdEntityForCrowdActorCore(const ZCrowdActorCore* pObstacle);
	static TArray<ZCrowdEntity*>* GetAllCrowds();
	static TEntityRef<ZCrowdEntity> GetCrowdEntityAtWorldPos(const float4& vWorldPos);
	static TEntityRef<ZCrowdEntity> GetCrowdByIndex(unsigned int nIndex);
	static ZCrowdEntity* GetActiveCrowd();
	void FindNextReusableCore();
	void ReleaseReusableCore(ZCrowdActorCore* pCore);
	const SMatrix& GetWorldMatrix() const;
	const SVector4& GetWarzoneOrigin() const;
	void FrameUpdate(const SGameUpdateEvent& updateEvent);
	void InitializeForSimulation();
	void UpdateMapsIfDirty(const SGameUpdateEvent& updateEvent);
	void SetPendingMapUpdate(int nFrameDelay);
	void OnForceWarzone();
	void OnSetOverrideStage(int nStage);
	void OnAllowInPanicOnly(bool bAllow);
	void OnAllowInGroup(bool bAllow);
	void OnGizmoChanged();
	void OnCrowdMapResourceChanged();
	void OnAIEntityFactoryChanged();
	void OnSetUseCrowdCamera(bool bValue);
	ZCrowdAnimationState& GetNextCrowdAnimationState();
	bool ShouldUpdateAnimation() const;
	void SyncWindowEventHandler();
	void FrameUpdateStopMode(const SGameUpdateEvent& updateEvent);
	void ActorTemplateResourceChanged(ZCrowdActorEntity* pTemplate, unsigned int nChangeFlags);
	void UpdateCellLocationInternal(ZCrowdActorCore* pObstacle, unsigned int nNewPackedCellIndex);
	void UpdateSphereRegions(float nDt);
	void MarkForFullRenderUpdate();
	bool ShouldSimulate() const;
	void AllocateCrowd();
	void DeallocateCrowd();
	void InitializeCrowdActors();
	void UpdateActorVisualVariations();
	void UpdateAvoidRegions();
	void ReleaseAvoidRegions();
	void AddAvoidRegions();
	void RemovePanicedActors(float nDt);
	void AddPanicDebris(float nDt);
	void DoHighLodSeparation();
	void DoSeparationPass(const TArray<ZCrowdActorCore*>& aActors);
	void CalculateAllValidRandomStartPositions(TArray<float4>* pResult);
	void CalculateAllValidGroupStartPositions(const unsigned int nGroupIndex, TArray<float4>* pResult) const;
	float4 PickRandomSpawnLocation(TArray<float4>& aPositions);
	static ZCrowdEntity* GetCrowdFromIndex(unsigned int nCrowdIndex);
	ZCrowdEntity& operator=(const ZCrowdEntity& __that);
};
