#pragma once

#include "ZEntityImpl.h"
#include "IHM5ActionEntityListener.h"
#include "ZEvent.h"
#include "SComponentMapEntry.h"
#include "SMatrix.h"
#include "TEntityRef.h"
#include "ZVariantRef.h"
#include "float4.h"

class ZActor;
class ZHitman5;
class IDynamicPhysics;
class ISequenceEntity;
class ZComponentCreateInfo;
class ZEventNull;
class ZHM5Action;
class ZHM5BaseCharacter;
class ZSpatialEntity;
class ZString;
struct SGameUpdateEvent;
struct STypeID;

class ZHM5BodyContainer : public ZEntityImpl, public IHM5ActionEntityListener
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	enum EBCState
	{
		BC_CLOSED = 0,
		BC_OPEN = 1,
		BC_FLUSH = 2,
		BC_OPENING = 3,
		BC_CLOSING = 4,
		BC_FLUSHING = 5
	};

	enum eBCCloseMode
	{
		BC_AUTOCLOSE = 0,
		BC_MANUALCLOSE = 1
	};

	enum EBCAnimSet
	{
		BC_CONTAINER_STANDARD = 0,
		BC_CONTAINER_WOODCHIPPER = 1,
		BC_CAR_STANDARD_TRUNK = 2,
		BC_CONTAINER_CLOSET = 3,
		BC_CONTAINER_LAUNDRYCHUTE = 4
	};

	enum EBCBodyMode
	{
		BC_1_VICTIM = 0,
		BC_2_VICTIMS = 1,
		BC_1_VICTIM_FLUSHABLE = 2,
		BC_1_VICTIM_AUTOFLUSHABLE = 3
	};

	enum
	{
		MAX_VICTIMS = 2
	};

	EBCState m_eBCState;
	TEntityRef<ZSpatialEntity> m_rBCLid;
	TEntityRef<ISequenceEntity> m_rSequenceEntity;
	TEntityRef<ZSpatialEntity> m_rStartPos;
	eBCCloseMode m_BCCloseMode;
	EBCAnimSet m_eBCAnimSet;
	EBCBodyMode m_eBodyMode;
	bool m_bEnabled;
	TEntityRef<ZHM5Action> m_rAction;
	TEntityRef<IDynamicPhysics> m_rLidPhysics;
	TEntityRef<ZActor> m_rVictims[2];
	unsigned int m_iNumVictims;
	float m_fLidAutoCloseTime;
	float4 m_vBCDir;
	bool m_bLastShowTargetsMustBeDeadSent;
	bool m_bDisabledHack;
	ZEvent<TEntityRef<ZHM5BodyContainer>, TEntityRef<ZActor>, ZEventNull, ZEventNull, ZEventNull> m_BodyDumpedEvent;

	static SComponentMapEntry s_componentMap[0];
	static unsigned int m_snOnFlushBodyStart;
	static unsigned int m_snOnFlushBodyEnd;
	static unsigned int m_snLidOpen;
	static unsigned int m_snLidOpened;
	static unsigned int m_snLidClose;
	static unsigned int m_snLidClosed;
	static unsigned int m_snFlushBodyEnabled;
	static unsigned int m_snFlushBodyDisabled;
	static unsigned int m_snStartDumpingBody;
	static unsigned int m_snEndDumpingBody;
	static unsigned int m_snGetContainerState;
	static unsigned int m_snContainerFull;
	static unsigned int m_snShowTargetsMustBeDead;

	~ZHM5BodyContainer() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Activate(const ZString& sSubset) override;
	void Deactivate(const ZString& sSubset) override;
	void Init() override;
	virtual void FrameUpdate(const SGameUpdateEvent& updateEvent);

	bool GetActionAABB(const ZHM5Action* pAction, float4& vMin, float4& vMax) const override;
	bool IsActionValid(ZHM5Action* pAction, const TEntityRef<ZHM5BaseCharacter>& pOperator) override;
	bool DisplayFarFeedback(ZHM5Action* pAction, const TEntityRef<ZHM5BaseCharacter>& pOperator) override;
	bool ActivateAction(ZHM5Action* pAction, const TEntityRef<ZHM5BaseCharacter>& pOperator) override;

	ZHM5BodyContainer() = default;
	static void RegisterType();
	ZHM5BodyContainer(ZComponentCreateInfo& pInfo);
	void OperateBodyContainer(const TEntityRef<ZHM5BaseCharacter>& pOperator);
	EBCState GetBCState() const;
	EBCAnimSet GetBCAnimSet() const;
	bool IsEmpty() const;
	bool IsFull() const;
	bool IsFlushing() const;
	bool IsClosed() const;
	bool CanDumpBodyInContainer() const;
	void SetUsed(TEntityRef<ZActor> rVictim);
	SMatrix GetAnimStartMatPos() const;
	SMatrix GetLidMatPos() const;
	bool CanFlushContainer() const;
	void OpenContainer();
	void ResetContainerOpenTimeDumpBody();
	unsigned int GetNumVictims() const;
	const TEntityRef<ZActor>& GetVictimReverseOrder(unsigned int idx) const;
	const TEntityRef<ZActor>& GetVictim(unsigned int idx) const;
	void SignalStartDumpingBody();
	void SignalEndDumpingBody(TEntityRef<ZActor> pActor);
	const float4 Get3dPromptPos() const;
	ZEvent<TEntityRef<ZHM5BodyContainer>, TEntityRef<ZActor>, ZEventNull, ZEventNull, ZEventNull>& GetBodyDumpedEvent();
	void SetDisabledHack();
	void OnEnable();
	void OnDisable();
	void OnDisableAndStopAllActions();
	void OnDisableVictim();
	void OnFlushBodyStart();
	void OnFlushBodyEnd();
	void OnGetContainerState();
	void InitializeBodyContainer();
	void OnBCLidChanged();
	void ActivateFrameUpdate();
	void DeactivateFrameUpdate();
	void InitBCAction();
	bool FixLid();
	void OpenLid(const TEntityRef<ZHM5BaseCharacter>& pOperator);
	void CloseLid(const TEntityRef<ZHM5BaseCharacter>& pOperator);
	void FlushContainer(const TEntityRef<ZHM5BaseCharacter>& pOperator);
	TEntityRef<ZHitman5> Hitman() const;
	void SetBCState(EBCState eBCState);
	bool IsInValidState(ZHM5Action* pAction, const TEntityRef<ZHM5BaseCharacter>& pOperator);
	void SendShowTargetsMustBeDeadSent(bool bValue);
};
