#pragma once

#include "ZEntityImpl.h"
#include "TFixedArray.h"
#include "TEntityRef.h"
#include "EPushResult.h"
#include "SVector4.h"
#include "ECrowdFlowUsage.h"
#include "CrowdUtil.h"
#include "EGait.h"
#include "ESpeed.h"
#include "MR.h"
#include "SComponentMapEntry.h"
#include "SMatrix.h"
#include "SVector2.h"
#include "ZVariantRef.h"
#include "float4.h"

class ZCrowdEntity;
class ZLinkedEntity;
class ZCrowdActorEntity;
struct SHitInfo;
class ZAnimationBoneData;
class ZAnimationBonePose;
class ZAnimationClipEntity;
class ZAnimationLibrary;
class ZCharacterController;
class ZComponentCreateInfo;
class ZCrowdActorCore;
class ZCrowdActorSensorInput;
class ZCrowdActorState;
class ZCrowdRegion;
class ZMapPoly;
struct SCrowdActorSensor;
struct STypeID;
template <class T> class TArrayRef;

class ZCrowdActor : public ZEntityImpl
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	enum EPossessionType
	{
		PT_NONE = 0,
		PT_CLOSE_COMBAT = 1,
		PT_ACT = 2
	};

	enum EAnimationOverride
	{
		AO_DISABLE_ALL = -2,
		AO_NORMAL_IDLE = -1
	};

	TFixedArray<unsigned char, 44> m_aStateMemoryBuffer;
	ZCrowdActorCore* m_pCore;
	ZCrowdActorSensorInput* m_pSensorInput;
	SCrowdActorSensor* m_pSensor;
	TEntityRef<ZCrowdEntity> m_pCrowdEntity;
	ZCrowdActorState* m_pCurState;
	float m_nTimeInState;
	bool m_bBeingPushed : 1;
	bool m_bStopFlag : 1;
	bool m_bWasScaredByRegion : 1;
	bool m_bNeverFlee : 1;
	bool m_bSelected : 1;
	bool m_bAllowRandomStateChanges : 1;
	float m_nSelectedTimer;
	unsigned char m_eFlowUsage;
	unsigned char m_nActorTemplateIndex;
	unsigned char m_nCurrentAccessFlags;
	unsigned char m_nGrantedAccessFlags;
	unsigned char m_eWantedGait;
	unsigned char m_eWantedSpeed;
	SVector2 m_vWantedDirection;
	SVector2 m_vWantedFacing;
	unsigned int m_nAnimSourceID;
	unsigned int m_nAnimSourceDataIndex;
	ZAnimationLibrary* m_pAnimLib;
	ZCharacterController* m_pCharacterController;
	short m_nPusherActorIndex;
	float m_nTotalPushTime;
	float m_nRemainingPushTime;
	float4 m_vPushVelocity;
	SVector4 m_vLookatTarget;
	ZCrowdRegion* m_pLookatRegion;
	float m_blendDelta;
	float m_nLookAtHMTimeOut;
	float m_aHomePosition[2];
	ZCrowdRegion* m_pCurCrowdRegion;
	unsigned char m_nVisualVariationIndex;
	float m_nSizeModifier;
	TEntityRef<ZLinkedEntity> m_pDrivingEntity;
	unsigned char m_nPossesionType;

	static SComponentMapEntry s_componentMap[0];
	static const unsigned int STATE_MEMORYBUFFER_SIZE;
	static ZMapPoly m_SmoothMapper;

	~ZCrowdActor() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Init() override;

	ZCrowdActor() = default;
	static void RegisterType();
	ZCrowdActor(const ZCrowdActor& __that);
	ZCrowdActor(ZComponentCreateInfo& Info);
	ZCrowdActorCore* GetCore() const;
	ZCrowdActorSensorInput* GetSensorInput() const;
	const SCrowdActorSensor* GetSensor() const;
	void SetCrowdEntity(const TEntityRef<ZCrowdEntity>& pEnt);
	const TEntityRef<ZCrowdEntity>& GetCrowdEntity() const;
	const TEntityRef<ZCrowdActorEntity> GetTemplate() const;
	bool IsManualActor() const;
	unsigned char GetActorTemplateIndex() const;
	bool IsEnabled() const;
	bool IsInCrowd() const;
	void Disable();
	void Enable();
	ECrowdFlowUsage GetFlowUsage() const;
	void SetFlowUsage(ECrowdFlowUsage eUsage);
	unsigned char GetCurrentLOD() const;
	bool IsCulled() const;
	void SetWantedFacing(const float4& vWantedFacing);
	void SetWantedMoveState(EGait eGait, ESpeed eSpeed, const float4& vWantedDirection, const float4& vWantedFacing);
	float4 GetWantedDirection() const;
	float4 GetWantedFacing() const;
	ESpeed GetWantedSpeed() const;
	EGait GetWantedGait() const;
	void RaiseStopFlag();
	bool GetStopFlag() const;
	void ClearStopFlag();
	float GetSpeed() const;
	void SetForward(const float4& v);
	float4 GetForward() const;
	float4 GetUp() const;
	float4 GetSide() const;
	float4 GetPosition() const;
	float4 GetVelocity() const;
	float4 GetCollisionPosition() const;
	void SetAnimationState(unsigned int nSource, unsigned int nIndex);
	unsigned int GetAnimSourceID() const;
	unsigned int GetAnimSourceIndex() const;
	ZCharacterController* GetCharacterController() const;
	ZAnimationLibrary* GetAnimationLibrary() const;
	void SetAnimationLibrary(ZAnimationLibrary* pAnimLib);
	void SetAnimationOverrideClips(TArrayRef<TEntityRef<ZAnimationClipEntity>> aOverrideClips);
	bool GetAnimationPose(const ZAnimationBoneData** ppBoneData, const ZAnimationBonePose** ppBonePose) const;
	bool IsRagdoll() const;
	bool IsStaticPose() const;
	bool IsCharControllerPose() const;
	bool IsPossessedActorPose() const;
	unsigned char GetPossessedAnimIndex() const;
	unsigned char GetRagdollIndex() const;
	unsigned int GetStaticPoseIndex() const;
	SMatrix GetWorldMatrix() const;
	SMatrix GetWorldMatrixNoScale() const;
	bool SetWorldPosition(const float4& vWorldPos, bool bAdjustHeightToCrowdMap);
	void SetPositionInCrowd(const float4& vNewCrowdPos, bool bAdjustHeight);
	float4 GetWorldPosition() const;
	float4 GetWorldForward() const;
	unsigned char GetAccessFlags() const;
	void AddAccessFlags(unsigned char nNewFlags);
	void RemoveAccessFlags(unsigned char nNewFlags);
	void SetCurrentAccessFlags(unsigned char nNewFlags);
	bool MovePositionInCrowdWithProjection(const float4& vOldCrowdPos, const float4& vNewCrowdPos, unsigned char nExtraAccessFlags);
	CrowdUtil::ECrowdActorMood GetMood() const;
	void EnterDefaultState(bool bStartIdle);
	void SetAllowRandomStateChanges(bool b);
	bool GetAllowRandomStateChanges() const;
	void SetHomePosition(const float4& vPos);
	float4 GetHomePosition() const;
	void SetNeverFlee(bool b);
	bool GetNeverFlee() const;
	ZCrowdActorState* GetCurrentState() const;
	float GetTimeInCurrentState() const;
	void SetTimeInCurrentState(float nTime);
	void YouGotHit(const SHitInfo& HitInfo);
	void Scare();
	void KillFromPose(const ZAnimationBonePose* pAnimPose, const SMatrix& mWorldMat);
	bool IsDead() const;
	bool IsScared() const;
	bool IsAlert() const;
	bool IsProne() const;
	bool WasScaredByRegion() const;
	void SetWasScaredByRegion(const bool b);
	void CrowdRegionPulse(ZCrowdRegion* pRegion);
	ZCrowdRegion* GetCurrentCrowdRegion() const;
	void Think(float nDeltaTimeSec);
	void IntegrateActor(float nDeltaTimeSec, float nCulledDeltaTimeSec, float nSteerFrames);
	int SampleEvents(MR::TriggeredEventsPool* pEventsPool, MR::TriggeredEventsBuffer* pEventsBuffer) const;
	bool IsPossessed() const;
	TEntityRef<ZLinkedEntity> GetDrivingEntity() const;
	bool PossessActor(TEntityRef<ZLinkedEntity> pLinked, EPossessionType ePossessionType);
	void DepossesActor();
	EPossessionType GetPossessionType() const;
	void SetPossessionType(EPossessionType nPossessionType);
	void SetSelected(bool bSelected);
	void SetSelectedTimer(float nTimer);
	float GetSelectedTimer() const;
	bool IsSelected() const;
	bool ShouldCollideWithCharacters() const;
	bool CanBePushed(ZCrowdActorCore* pPusher) const;
	bool IsBeingPushed() const;
	bool IsBeingPushedBy(short nActorIndex);
	float4 GetPushVelocity() const;
	EPushResult PushActor(ZCrowdActorCore* pPusher, const float4& vPusherMoveVector, bool bHardPush);
	void SetVisualVariationIndex(unsigned char nIndex);
	unsigned char GetVisualVariationIndex() const;
	void SetSizeModifier(float nSizeMod);
	float GetSizeModifier() const;
	void SetSpeed(float s);
	void IntegrateFromAnimController(float nDeltaTimeSec, ZCrowdActorCore& pCore);
	void IntegrateFromSteering(float nDeltaTimeSec);
	void IntegratePossessed(float nDeltaTimeSec);
	void HandlePush(float nDeltaTimeSec);
	void HandleCrowdRegion();
	void UpdateStopFlag();
	void ResetSimulationState();
	bool ChangeState(ZCrowdActorState* pNewState);
	void SwitchToRagdoll(unsigned int nDeathFlags, bool bCriticalDeath);
	ZCrowdActor& operator=(const ZCrowdActor& __that);
};
