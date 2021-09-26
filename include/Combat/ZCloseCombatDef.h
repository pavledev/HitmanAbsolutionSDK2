#pragma once

#include "ZEntityImpl.h"
#include "SActorSoundDefs.h"
#include "EAIEventType.h"
#include "SComponentMapEntry.h"
#include "TArray.h"
#include "ZVariantRef.h"

class ZActor;
struct float4;
class ZComponentCreateInfo;
struct STypeID;
template <class T> class TEntityRef;

class ZCloseCombatDef : public ZEntityImpl
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	struct SActorNoise
	{
		SActorSoundDefs::EDefinition m_iSpeak;
		EAIEventType m_eAIEvent;
		float m_fAIEventDistance;
	};

	TArray<SActorNoise> m_ActorNoiseList;

	static SComponentMapEntry s_componentMap[0];

	~ZCloseCombatDef() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Init() override;

	ZCloseCombatDef() = default;
	static void RegisterType();
	ZCloseCombatDef(ZComponentCreateInfo& info);
	void SendNoise(TEntityRef<ZActor> pActor, const float4& vPosition, int iNoiseLevel);
};
