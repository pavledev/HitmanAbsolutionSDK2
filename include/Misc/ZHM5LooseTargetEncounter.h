#pragma once

#include "ZEntityImpl.h"
#include "TEntityRef.h"
#include "SComponentMapEntry.h"
#include "ZVariantRef.h"

class ZHitman5;
class ISequenceEntity;
class ZComponentCreateInfo;
class ZSequenceEntity;
class ZString;
struct STypeID;

class ZHM5LooseTargetEncounter : public ZEntityImpl
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	TEntityRef<ZSequenceEntity> m_rLooseSequence;
	bool m_bEnabled;
	bool m_bActivated : 1;
	bool m_bDeactivatingCheckpoint : 1;
	bool m_bLevelEnded : 1;

	static SComponentMapEntry s_componentMap[0];

	~ZHM5LooseTargetEncounter() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Activate(const ZString& sSubset) override;
	void Deactivate(const ZString& sSubset) override;
	void Init() override;

	ZHM5LooseTargetEncounter() = default;
	static void RegisterType();
	ZHM5LooseTargetEncounter(ZComponentCreateInfo& info);
	void StartCutSequence();
	bool IsWaitingForHMToDie() const;
	void Prepare();
	void OnSequenceStop(ISequenceEntity* pSequence);
	void OnSequenceAbort(ISequenceEntity* pSequence);
	TEntityRef<ZSequenceEntity> GetSequence() const;
	void OnEnable();
	void OnDisable();
	void RegisterEventHandlers();
	void UnregisterEventHandlers();
	void RegisterOnHitman();
	void UnregisterOnHitman();
	void StopCutSequence();
	TEntityRef<ZHitman5> Hitman() const;
};
