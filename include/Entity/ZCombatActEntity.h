#pragma once

#include "ZSpatialEntity.h"
#include "ZResourcePtr.h"
#include "SActorSoundDefs.h"
#include "SComponentMapEntry.h"
#include "SMatrix.h"
#include "SVector3.h"
#include "TEntityRef.h"
#include "ZVariantRef.h"

class IChildNetworkEntity;
class ZComponentCreateInfo;
class ZString;
struct STypeID;
struct float4;

class ZCombatActEntity : public ZSpatialEntity
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	ZResourcePtr m_pGizmo;
	SActorSoundDefs::EDefinition m_eDialog;
	bool m_bEnableOnStart;
	bool m_bAlignActor;
	bool m_bEnableDefault;
	bool m_bEnableReverse;
	float m_fTriggerRadius;
	float m_fDefaultRadius;
	float m_fDefaultAlignAngle;
	float m_fDefaultActivationAngle;
	float m_fDefaultActivationArc;
	SVector3 m_vDefaultAlignOffset;
	float m_fReverseRadius;
	float m_fReverseAlignAngle;
	float m_fReverseActivationAngle;
	float m_fReverseActivationArc;
	SVector3 m_vReverseAlignOffset;
	TEntityRef<IChildNetworkEntity> m_pDefaultAct;
	TEntityRef<IChildNetworkEntity> m_pReverseAct;
	bool m_bIsActive;
	bool m_bIsLocked;
	bool m_bActivated;

	static SComponentMapEntry s_componentMap[0];
	static const int SUBACT_DEFAULT;
	static const int SUBACT_REVERSE;

	~ZCombatActEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Activate(const ZString& sSubset) override;
	void Deactivate(const ZString& sSubset) override;
	void Init() override;

	ZCombatActEntity() = default;
	static void RegisterType();
	ZCombatActEntity(ZComponentCreateInfo& info);
	void LockAct();
	void UnlockAct();
	bool IsPointInRange(const float4& vPos);
	TEntityRef<IChildNetworkEntity> GetActToPlay(int nSubActIndex);
	bool IsSubActEnabled(int nSubAct);
	float GetAngleOutsideCone(int nSubAct, const float4& vTestPos);
	float GetActAlignAngle(int nSubActIndex) const;
	SVector3 GetActAlignOffset(int nSubActIndex) const;
	float GetActActivationAngle(int nSubActIndex) const;
	float GetActActivationArc(int nSubActIndex) const;
	SMatrix GetLocalAlignMatrix(int nSubActIndex) const;
	SMatrix GetWorldAlignMatrix(int nSubActIndex) const;
	SMatrix GetLocalActivationMatrix(int nSubActIndex) const;
	SMatrix GetWorldActivationMatrix(int nSubActIndex) const;
	bool ShouldAlignActor() const;
	SMatrix ConstrainedWorldTransform(int nSubActIndex) const;
	SActorSoundDefs::EDefinition GetDialog() const;
	void OnEnable();
	void OnDisable();
	void OnGizmoChanged();
};
