#pragma once

#include "ZEntityImpl.h"
#include "EActorCCPreset.h"
#include "SComponentMapEntry.h"
#include "ZVariantRef.h"

class ZComponentCreateInfo;
struct STypeID;

class ZHM5CCProfile : public ZEntityImpl
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	int m_nAttacksForTakeDown;
	float m_fTakeDownWindow;
	float m_fTakeDownWindowIncFraction;
	float m_fHitmanDamage;
	bool m_bAllowAttackingHitman;
	float m_fDecayTime;
	int m_nKillMashNum;
	int m_nNumChainsToKill;
	EActorCCPreset m_eActorCCPreset;

	static SComponentMapEntry s_componentMap[0];
	static ZHM5CCProfile* s_apPresetCCProfile[9];
	static bool s_bClearStaticArray;

	~ZHM5CCProfile() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Init() override;

	ZHM5CCProfile() = default;
	static void RegisterType();
	ZHM5CCProfile(ZComponentCreateInfo& info);
	static ZHM5CCProfile* GetDefaultCCProfile(EActorCCPreset eActorCCPreset);
};
