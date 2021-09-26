#pragma once

#include "ZEntityImpl.h"
#include "EActorPerceptionSensitivity.h"
#include "SComponentMapEntry.h"
#include "TArray.h"
#include "ZVariantRef.h"

struct SKnownEntity;
class ZComponentCreateInfo;
struct STypeID;
struct SVector2;
template <class T> class TArrayRef;
template <class T> class TRefCountPtr;

class ZSharedSensorDef : public ZEntityImpl
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	struct SVisibilitySetting
	{
		EActorPerceptionSensitivity m_eSensitivity;
		float m_fCloseRange;
		float m_fPeripheralRange;
		float m_fPeripheralAngle;
		float m_fPeripheralHigh;
		float m_fPeripheralLow;
		float m_fFocusConeWidthAngle;
		float m_fFocusConeHeightAngle;
		float m_fFocusConeRange;
	};

	TArray<SVisibilitySetting> m_VisibilitySetting;
	float m_fDisguiseAttractionDistanceNear;
	float m_fDisguiseAttractionDistanceMid;
	float m_fDisguiseAttractionDistanceFar;
	float m_fDisguiseAttractionDistanceInCrowdFactor;
	float m_fDisguiseAttentionTimeNear;
	float m_fDisguiseAttentionTimeMid;
	float m_fDisguiseAttentionTimeFar;
	float m_fDisguiseAttractionTimeInCrowdFactor;
	float m_fDisguiseFollowTime;
	float m_fTrespassingPeripheralAngle;
	float m_fTrespassingAttractionRunPenalty;
	float m_fTrespassingAttractionHumanShieldPenalty;
	float m_fTrespassingSoftSpottingTime;
	float m_fTrespassingSoftSpottingTimeCrowd;
	TArray<SVector2> m_TrespassingAttentionDuration;
	TArray<SVector2> m_TrespassingPeripheralAttentionDuration;
	float m_fHuntedPeripheralAngle;
	float m_fHuntedAttractionRunPenalty;
	float m_fHuntedAttractionHumanShieldPenalty;
	TArray<SVector2> m_HuntedAttentionDuration;
	TArray<SVector2> m_HuntedPeripheralAttentionDuration;
	float m_fAttentionDecreaseTime;
	float m_fLookAtMinAttention;
	float m_fTurnLookAtMinAttention;
	float m_nCrowdAttentionModifier[4];
	float m_nCrowdAttentionRangeModifier[4];

	static SComponentMapEntry s_componentMap[0];

	~ZSharedSensorDef() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;

	ZSharedSensorDef() = default;
	static void RegisterType();
	ZSharedSensorDef(ZComponentCreateInfo& info);
	void SetCrowdAttentionModifiers(float* pAttentionModifiers, float* pRangeModifiers);
	void SetCrowdAttentionModifiers(float nAttentionModifier, float nRangeModifier);
	float GetAttentionDecreaseTime() const;
	void GetCombatAttention(const TRefCountPtr<SKnownEntity>& pSelf, const TRefCountPtr<SKnownEntity>& pTarget, float& fAttentionIncrease) const;
	void GetHuntedAttention(const TRefCountPtr<SKnownEntity>& pSelf, const TRefCountPtr<SKnownEntity>& pTarget, float& fAttentionIncrease) const;
	float GetDisguiseAttentionTime(float fDistance, float fOutfitRating) const;
	void GetDisguiseAttention(const TRefCountPtr<SKnownEntity>& pSelf, const TRefCountPtr<SKnownEntity>& pTarget, float fOutfitRating, float& fAttentionIncrease) const;
	void GetTrespassingAttention(const TRefCountPtr<SKnownEntity>& pSelf, const TRefCountPtr<SKnownEntity>& pTarget, float& fAttentionIncrease, float fGraphScale) const;
	bool IsVisionLimited(const TRefCountPtr<SKnownEntity>& pSelf, const TRefCountPtr<SKnownEntity>& pTarget) const;
	float GetDisguiseFollowTime() const;
	bool GetShouldLookAt(float fAttention) const;
	bool GetShouldTurnLookAt(float fAttention) const;
	const SVisibilitySetting& GetVisibilitySettingFromSensitivity(EActorPerceptionSensitivity eSensitivity) const;
	float GetGraphValue(TArrayRef<SVector2> graph, float x, float fScaleX) const;
	float GetNormalizedLinearGraphValue(TArrayRef<SVector2> graph, float x, float fScaleX) const;
};
