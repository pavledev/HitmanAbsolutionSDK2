#pragma once

#include "ZEntityImpl.h"
#include "ICharacterAct.h"
#include "IActListener.h"
#include "TEntityRef.h"
#include "EActorPerceptionSensitivity.h"
#include "EActorEmotionState.h"
#include "SComponentMapEntry.h"
#include "TArray.h"
#include "ZVariantRef.h"

class IActorAction;
class IChildNetworkEntity;
class ZActor;
class ZBoneAttachEntity;
class ZComponentCreateInfo;
class ZSpatialEntity;
class ZString;
struct STypeID;

class ZChildNetworkActEntity : public ZEntityImpl, public ICharacterAct, public IActListener
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	TArray<TEntityRef<ZBoneAttachEntity>> m_aBoneAttachers;
	TArray<TEntityRef<IActorAction>> m_aActorItemActions;
	TEntityRef<IChildNetworkEntity> m_pChildNetwork;
	TEntityRef<ZSpatialEntity> m_pApproachLookAtPoint;
	bool m_bEnableAmbientLookat;
	bool m_bBlendDirectFromWalk;
	bool m_bBlendUpperBodyAtStart;
	bool m_bBlendUpperBodyAtEnd;
	bool m_bEnabled;
	float m_fDuration;
	EActorPerceptionSensitivity m_ePerceptionSensitivity;
	EActorEmotionState m_eRequiredEmotionState;
	bool m_bAllowRagdollDamageReactions;
	bool m_bAllowReactToSillyHitman;
	TEntityRef<ZActor> m_pActor;
	bool m_bStoredReactToSilly : 1;
	bool m_bCleanupRequired : 1;

	static SComponentMapEntry s_componentMap[0];
	static unsigned int s_OnAnimEvent4001;
	static unsigned int s_OnAnimEvent4002;
	static unsigned int s_OnAnimEvent4003;
	static unsigned int s_OnAnimEvent4004;
	static unsigned int s_OnAnimEvent4005;
	static unsigned int s_OnAnimEvent4006;
	static unsigned int s_OnAnimEvent4007;

	~ZChildNetworkActEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Activate(const ZString& sSubset) override;
	void Deactivate(const ZString& sSubset) override;
	void Init() override;

	void OnActStart() override;
	void OnActFinished() override;
	void OnActLoopStart() override;
	void OnActInFullbody() override;
	void OnActBehaviorEvent(unsigned int nEventId, float fEventWeight) override;

	ZChildNetworkActEntity() = default;
	static void RegisterType();
	ZChildNetworkActEntity(ZComponentCreateInfo& info);
	bool GetIsValid(const TEntityRef<ZActor>& pActor);
	bool IsPrepared(const TEntityRef<ZActor>& pActor);
	bool PrepareAct(const TEntityRef<ZActor>& pActor);
	void ReleaseAct(const TEntityRef<ZActor>& pActor);
	TEntityRef<IChildNetworkEntity> GetChildNetwork() const;
	float GetDuration();
	TEntityRef<ZSpatialEntity> GetApproachLookAtPoint();
	const TArray<TEntityRef<ZBoneAttachEntity>>& GetBoneAttachers() const;
	const TArray<TEntityRef<IActorAction>>& GetActorItemActions() const;
	void OnEnable();
	void OnDisable();
	void CleanUp();
};
