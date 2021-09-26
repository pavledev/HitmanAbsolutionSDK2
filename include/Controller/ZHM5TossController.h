#pragma once

#include "ZHM5BaseController.h"
#include "EHM5BaseControllerType.h"
#include "EHM5ResetReason.h"
#include "SMatrix.h"
#include "TArray.h"
#include "TEntityRef.h"
#include "ZGameTime.h"
#include "ZMapPoly.h"
#include "float4.h"

class ZHM5MovementToss;
class IHM5Item;
class ZActor;
class IMorphemeEntity;
class ZHM5CCEffects;
class ZHitman5;
class ZHitmanMorphemePostProcessor;
class ZMorphemeNetworkInstance;
struct SGameUpdateEvent;
struct SHM5ControllerUpdateEvent;

class ZHM5TossController : public ZHM5BaseController
{
public:
	enum EThrowType
	{
		eThrowTypeStandNormal = 0,
		eThrowTypeStandNormal90Right = 1,
		eThrowTypeCrouchNormal = 2,
		eThrowTypeCrouchNormal90Right = 3,
		eThrowTypeCoverNormalHighLeft = 4,
		eThrowTypeCoverNormalHighRight = 5,
		eThrowTypeCoverNormalLowLeft = 6,
		eThrowTypeCoverNormalLowRight = 7,
		eThrowTypeCoverNormalHighLeft180 = 8,
		eThrowTypeCoverNormalHighRight180 = 9,
		eThrowTypeCoverNormalLowLeft180 = 10,
		eThrowTypeCoverNormalLowRight180 = 11,
		eThrowTypeStandDeadly135Left = 12,
		eThrowTypeStandDeadly = 13,
		eThrowTypeStandDeadly135Right = 14,
		eThrowTypeCrouchDeadly135Left = 15,
		eThrowTypeCrouchDeadly = 16,
		eThrowTypeCrouchDeadly135Right = 17,
		eThrowTypeStandDeadlyHeavy135Left = 18,
		eThrowTypeStandDeadlyHeavy = 19,
		eThrowTypeStandDeadlyHeavy135Right = 20,
		eThrowTypeCrouchDeadlyHeavy135Left = 21,
		eThrowTypeCrouchDeadlyHeavy = 22,
		eThrowTypeCrouchDeadlyHeavy135Right = 23,
		eThrowTypeCoverDeadlyHighLeft = 24,
		eThrowTypeCoverDeadlyHighRight = 25,
		eThrowTypeCoverDeadlyLowLeft = 26,
		eThrowTypeCoverDeadlyLowRight = 27,
		eThrowTypeCoverDeadlyHeavyHighLeft = 28,
		eThrowTypeCoverDeadlyHighLeft180 = 29,
		eThrowTypeCoverDeadlyHeavyHighRight = 30,
		eThrowTypeCoverDeadlyHighRight180 = 31,
		eThrowTypeCoverDeadlyHeavyLowLeft = 32,
		eThrowTypeCoverDeadlyLowLeft180 = 33,
		eThrowTypeCoverDeadlyHeavyLowRight = 34,
		eThrowTypeCoverDeadlyLowRight180 = 35,
		eThrowTypeCoverDeadlyHeavyHighRight180 = 36,
		eThrowTypeCoverDeadlyHeavyHighLeft180 = 37,
		eThrowTypeCoverDeadlyHeavyLowRight180 = 38,
		eThrowTypeCoverDeadlyHeavyLowLeft180 = 39,
		eThrowTypeLast = 40
	};

	struct SReleasedItem
	{
		TEntityRef<IHM5Item> m_rItem;
		ZGameTime m_ReleaseTime;
		EThrowType m_eThrowType;
		bool m_bStuckInTarget;
		bool m_bImpactForceApplied;
		float m_fCollisionDisableTime;
		float m_fRotation;
		float m_fRotationSign;
		float m_fVelocity;
		SMatrix m_mvLastAlignedMatPos;
		SMatrix m_mvTargetBoneOffset;
		TEntityRef<ZActor> m_pTarget;

		SReleasedItem(const SReleasedItem& __that);
		SReleasedItem(const TEntityRef<IHM5Item>& rItem, ZGameTime releaseTime, EThrowType eThrowType, float fCollisionDisableTime, TEntityRef<ZActor> pTarget);
		~SReleasedItem() = default;
		SReleasedItem& operator=(const SReleasedItem& __that);
	};

	struct STossParameters
	{
		float m_fTossTime;
		float m_fTossLength;
		float m_fVecticalVelocity;
		float m_fHorizontalVelocity;
		bool m_bIsValid;

		STossParameters() = default;
	};

	struct STrajectoryPoint
	{
		float4 m_vPos;
		float m_fTime;

		STrajectoryPoint(const float4& vPos, float fTime);
		STrajectoryPoint() = default;
	};

	TEntityRef<ZHitman5> m_pHitman;
	TEntityRef<IMorphemeEntity> m_MorphemeEntity;
	ZMorphemeNetworkInstance* m_pMrNetwork;
	ZHitmanMorphemePostProcessor* m_pPostProcessor;
	ZHM5MovementToss* m_pTossMovement;
	ZMapPoly m_Mapper;
	bool m_bInitialized;
	bool m_bIsAiming;
	bool m_bThrowReady;
	EThrowType m_eThrowType;
	EThrowType m_ePrevThrowType;
	STossParameters m_sTossParams;
	TArray<STrajectoryPoint> m_aTrajectoryPoints;
	float m_fMaxLength;
	float m_fTossVelocity;
	float m_fPrevTossVelocity;
	TEntityRef<ZActor> m_pDeadlyThrowTarget;
	TEntityRef<ZActor> m_pPrevDeadlyThrowTarget;
	TArray<SReleasedItem> m_aReleasedItems;
	TArray<float4> m_ArcPositions;
	bool m_bTossArchDirty;
	TEntityRef<ZHM5CCEffects> m_rEffects;
	float4 m_vIntersectionNormal;
	bool m_bNewDeadlyThrowTarget;
	float m_fCameraBlendInTime;
	float m_fDeadlyThrowLockTime;
	float m_fHintWeight;

	~ZHM5TossController() override = default;
	void Update(const SHM5ControllerUpdateEvent& HM5ControllerUpdateEvent) override;
	void Reset(EHM5ResetReason eResetReason) override;

	ZHM5TossController() = default;
	ZHM5TossController(const TEntityRef<ZHitman5>& pHitman, EHM5BaseControllerType eType);
	const STossParameters* GetTossParameters() const;
	float4 GetTossPosAtTime(float fTime) const;
	float4 GetTossPosAtTimeFraction(float fTimeFraction) const;
	float GetTossTimeAtEnd() const;
	EThrowType GetThrowType() const;
	const TEntityRef<ZActor> GetDeadlyThrowTarget() const;
	bool IsThrowReady() const;
	bool IsHoldingThrowableItem() const;
	bool IsHoldingDeadlyThrowItem() const;
	bool IsDeadlyThrowType(EThrowType eThrowType) const;
	bool IsCoverThrowType(EThrowType eThrowType) const;
	bool IsHeavythrowType(EThrowType eThrowType) const;
	bool Is180ThrowType(EThrowType eThrowType) const;
	bool ReverseCamDirForThrowType(EThrowType eThrowType) const;
	void PushReleasedItem(const TEntityRef<IHM5Item>& rItem, ZGameTime releaseTime, EThrowType eThrowType, float fCollisionDisableTime, TEntityRef<ZActor> pTarget);
	void HandleItemPickup(const TEntityRef<IHM5Item>& rItem);
	void Initialize(const TEntityRef<IMorphemeEntity>& rMorphemeEntity, ZHitmanMorphemePostProcessor* pPostProcessor);
	bool IsAiming() const;
	float GetCameraBlendInFraction() const;
	TEntityRef<ZHitman5> Hitman() const;
	void ClearTossArchData();
	void UpdateNormalThrow(const SHM5ControllerUpdateEvent& HM5ControllerUpdateEvent);
	EThrowType SelectNormalThrowType();
	EThrowType SelectDeadlyThrowType(TEntityRef<ZActor> rActor);
	void UpdateDeadlyThrow(const SHM5ControllerUpdateEvent& HM5ControllerUpdateEvent);
	void UpdateReleasedItems(const SGameUpdateEvent& updateEvent);
	void CalculateTossParameters(const SHM5ControllerUpdateEvent& HM5ControllerUpdateEvent);
	bool CheckValidThrow();
	bool CheckValidDeadlyThrow(TEntityRef<ZActor> rTarget);
	float4 CalcThrowDir(EThrowType eThrowType, const SMatrix& mvHitmanMatPos, const SMatrix& mvDeadlythrowTarget) const;
	bool CalculateTrajectory(const SHM5ControllerUpdateEvent& HM5ControllerUpdateEvent);
	void CalculateMaxLength();
	void SampleTrajectory();
	void InitializeTossArc();
	void ApplyDeadlyThrowImpulse(SReleasedItem& rReleasedItem);
	void PopReleasedItem(unsigned int nIndex, bool bEnablePickup);
	void CancelThrow(const SGameUpdateEvent& updateEvent);
	void UpdateTossVelocity();
	float GetDeadlyThrowRotationSign(EThrowType eThrowType) const;
	SMatrix GetCameraAlignedMatPos();
};
