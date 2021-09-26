#pragma once

#include "ZReusablePropEntity.h"
#include "IHM5ActionEntityListener.h"
#include "SComponentMapEntry.h"
#include "SMatrix.h"
#include "TArray.h"
#include "TEntityRef.h"
#include "ZVariantRef.h"

class ISequenceEntity;
class ZComponentCreateInfo;
class ZHM5Action;
class ZHM5BaseCharacter;
class ZHM5BodyContainer;
class ZHitman5;
class ZSpatialEntity;
class ZString;
struct SGameUpdateEvent;
struct STypeID;
struct float4;

class ZHM5Closet : public ZReusablePropEntity, public IHM5ActionEntityListener
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	enum EClosetType
	{
		eTypeClosetNormal = 0,
		eTypeClosetCake = 1,
		eTypeClosetDumpster = 2,
		eTypeClosetLast = 3
	};

	TArray<TEntityRef<ZSpatialEntity>> m_Doors;
	TEntityRef<ZSpatialEntity> m_rCloset;
	TEntityRef<ISequenceEntity> m_rEnterSequence;
	TEntityRef<ISequenceEntity> m_rExitSequence;
	TEntityRef<ISequenceEntity> m_rPeekExitSequence;
	TEntityRef<ISequenceEntity> m_rPeekSequence;
	TEntityRef<ZHM5Action> m_rAction;
	TEntityRef<ZSpatialEntity> m_rPeekCameraPosition;
	EClosetType m_eClosetType;
	TEntityRef<ZHM5BodyContainer> m_rBodyContainer;
	float m_fHorizontalAngleLimit;
	float m_fVerticalAngleLimit;

	static SComponentMapEntry s_componentMap[0];
	static unsigned int m_snOnEnterCloset;
	static unsigned int m_snEnterClosetDone;
	static unsigned int m_snExitClosetStart;
	static unsigned int m_snExitClosetDone;

	~ZHM5Closet() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Activate(const ZString& sSubset) override;
	void Deactivate(const ZString& sSubset) override;
	void Init() override;
	void Start() override;
	virtual void FrameUpdate(const SGameUpdateEvent& updateEvent);

	bool GetActionAABB(const ZHM5Action* pAction, float4& vMin, float4& vMax) const override;
	bool IsActionValid(ZHM5Action* pAction, const TEntityRef<ZHM5BaseCharacter>& pOperator) override;
	bool DisplayFarFeedback(ZHM5Action* pAction, const TEntityRef<ZHM5BaseCharacter>& pOperator) override;
	bool ActivateAction(ZHM5Action* pAction, const TEntityRef<ZHM5BaseCharacter>& pOperator) override;

	ZHM5Closet() = default;
	static void RegisterType();
	ZHM5Closet(ZComponentCreateInfo& pInfo);
	EClosetType GetClosetType() const;
	void SetupCameraAndAction();
	void ActivateFrameUpdate();
	SMatrix GetClosetMatrix() const;
	void ActivateExitCloset();
	void ActivateEnterClosetAnimation();
	void ActivateExitClosetAnimation();
	void EnterClosetAnimationDone();
	void ExitClosetAnimationDone();
	void DeactivateFrameUpdate();
	void OnEnterCloset();
	void OnExitCloset();
	TEntityRef<ZHitman5> Hitman() const;
	void ActivateHideInCloset();
	bool IsInValidState(ZHM5Action* pAction, const TEntityRef<ZHM5BaseCharacter>& pOperator);
};
