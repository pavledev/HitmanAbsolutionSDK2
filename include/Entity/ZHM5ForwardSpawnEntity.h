#pragma once

#include "ZEntityImpl.h"
#include "TEntityRef.h"
#include "EGameTension.h"
#include "SComponentMapEntry.h"
#include "ZVariantRef.h"

class IMusicComposition;
class ISoundAmbienceElement;
class ZComponentCreateInfo;
class ZHM5ValueEntity_bool;
class ZSpatialEntity;
class ZString;
struct STypeID;

class ZHM5ForwardSpawnEntity : public ZEntityImpl
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	enum EState
	{
		eState_Undefined = 0,
		eState_Enabled = 1,
		eState_Triggered = 2,
		eState_DisabledByTension = 3,
		eState_NotSupportedInLevel = 4
	};

	EState m_eState;
	TEntityRef<ZSpatialEntity> m_rPosToSpawnHitmanOn;
	bool m_eDifficulty_Level1;
	bool m_eDifficulty_Level2;
	bool m_eDifficulty_Level3;
	bool m_eDifficulty_Level4;
	bool m_eDifficulty_Level5;
	TEntityRef<ZHM5ValueEntity_bool> m_pStateEnabled;
	TEntityRef<ZHM5ValueEntity_bool> m_pStateTriggered;
	TEntityRef<ZHM5ValueEntity_bool> m_pStateDisabledByTension;
	TEntityRef<ZHM5ValueEntity_bool> m_pStateNotSupported;
	TEntityRef<ISoundAmbienceElement> m_pInitialSoundAmbience;
	TEntityRef<IMusicComposition> m_pInitialComposition;
	bool m_bTriggered : 1;
	bool m_bSupportedInLevel : 1;

	static SComponentMapEntry s_componentMap[0];
	static unsigned int m_snOnRestore;

	~ZHM5ForwardSpawnEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Activate(const ZString& sSubset) override;
	void Deactivate(const ZString& sSubset) override;
	void Init() override;

	ZHM5ForwardSpawnEntity() = default;
	static void RegisterType();
	ZHM5ForwardSpawnEntity(ZComponentCreateInfo& pInfo);
	void ResetTriggered();
	TEntityRef<ZSpatialEntity> GetPosToSpawnHitmanOn();
	void SignalOnRestore();
	void ActivateSound();
	void OnTrigger();
	bool IsAvailableOnDifficultyLevel(int iDifficultyLevel) const;
	void UpdateState();
	EState GetNextState();
	void OnGameTensionChanged(EGameTension tension);
};
