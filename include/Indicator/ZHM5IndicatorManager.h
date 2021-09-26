#pragma once

#include "IComponentInterface.h"
#include "TArray.h"
#include "TEntityRef.h"
#include "float4.h"
#include "ZVariantRef.h"

class ZHitman5;
class ZSpatialEntity;
struct SComponentMapEntry;
struct STypeID;

class ZHM5IndicatorManager : public IComponentInterface
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	enum EIndicatorType
	{
		eActorAmbient = 0,
		eActorAlertedLow = 1,
		eActorAlertedHigh = 2,
		eActorArrest = 3,
		eActorCombat = 4,
		eExplosion = 5,
		eObjective = 6,
		ePointOfInterest = 7,
		eContractExit = 8,
		eEasterActor = 9
	};

	enum EIndicatorHeight
	{
		eAbove = 0,
		eOnLevel = 1,
		eBelow = 2
	};

	struct SInternalIndicator
	{
		float4 m_vPos;
		TEntityRef<ZSpatialEntity> m_rSpatialEntity;
		bool m_bActor : 1;

		SInternalIndicator(const SInternalIndicator& __that);
		SInternalIndicator() = default;
		~SInternalIndicator() = default;
		SInternalIndicator& operator=(const SInternalIndicator& __that);
	};

	struct SHudIndicator
	{
		float fDistance;
		float fDegrees;
		float fFacingDirection;
		EIndicatorType m_eIndicatorType;
		EIndicatorHeight m_eIndicatorHeight;
		bool m_bVisibleToHitman : 1;
		bool m_bDisplay : 1;
	};

	struct SIndicator
	{
		SInternalIndicator m_sInternal;
		SHudIndicator m_sHud;

		SIndicator(const SIndicator& __that);
		SIndicator() = default;
		~SIndicator() = default;
		SIndicator& operator=(const SIndicator& __that);
	};

	TArray<SIndicator> m_ActiveIndicators;
	bool m_bEasterActorEnabled;

	static const float m_sfMaxActorCutOffDistance;

	~ZHM5IndicatorManager() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;

	ZHM5IndicatorManager() = default;
	const SComponentMapEntry* GetComponentInterfacesInternal() const;
	void AddIndicator(TEntityRef<ZSpatialEntity> rSpatialEntity, const float4& vPos, EIndicatorType eIndicatorType);
	void AddActorIndicator(TEntityRef<ZSpatialEntity> rSpatialEntity, const float4& vPos, EIndicatorType eIndicatorType, bool bVisible);
	void RemoveIndicator(TEntityRef<ZSpatialEntity> rSpatialEntity);
	void RemoveAllActorIndicators();
	const TArray<SIndicator>& GetActiveIndicators();
	int GetNumStaticIcons();
	void CalcHeightToHitman(const float4& vPosHitman);
	void ForceDisplay(bool bDisplay);
	bool UpdatePosAndConvertToHud();
	bool IsInArray(const TEntityRef<ZSpatialEntity> rSpatialEntity) const;
	float GetDistanceSqr(const float4& vPosObject) const;
	TEntityRef<ZHitman5> Hitman() const;
};
