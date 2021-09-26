#pragma once

#include "ZSpatialEntity.h"
#include "SVector2.h"
#include "ZResourcePtr.h"
#include "SComponentMapEntry.h"
#include "TEntityRef.h"
#include "ZEntityRef.h"
#include "ZVariantRef.h"

class ZHM5GuideVentilatorShaft;
class ZComponentCreateInfo;
struct SMatrix43;
struct STypeID;

class ZHM5VentilatorShaftNodeEntity : public ZSpatialEntity
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	enum EType
	{
		TypeNode = 0,
		TypeEventHole = 1,
		TypeEntranceHigh = 2,
		TypeEntranceLow = 3
	};

	SVector2 m_vArmMovementHorizontal;
	SVector2 m_vArmMovementVertical;
	ZResourcePtr m_pHelper;
	TEntityRef<ZHM5GuideVentilatorShaft> m_rMasterGuide;
	unsigned int m_iSplineIdx;

	static SComponentMapEntry s_componentMap[0];

	~ZHM5VentilatorShaftNodeEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Init() override;
	virtual void ResetNode();
	virtual EType GetType() const;
	virtual void GeomTransformChangeCallback(const ZEntityRef& entity, const SMatrix43& mNewValue);

	ZHM5VentilatorShaftNodeEntity() = default;
	static void RegisterType();
	void OnHelperChanged();
	ZHM5VentilatorShaftNodeEntity(ZComponentCreateInfo& Info);
	void SetMasterGuide(TEntityRef<ZHM5GuideVentilatorShaft>& Ref);
	void SetSplineIdx(unsigned int iValue);
	unsigned int GetSplineIdx() const;
	const SVector2& GetArmMovementHorizontal() const;
	const SVector2& GetArmMovementVertical() const;
	void OnArmMovementHorizontalChanged();
	void OnArmMovementVerticalChanged();
};
