#pragma once

#include "ZEntityImpl.h"
#include "TEntityRef.h"
#include "SComponentMapEntry.h"
#include "ZVariantRef.h"

class ZCharacterTemplateAspect;
class ZHitman5;
class ZComponentCreateInfo;
struct SGameUpdateEvent;
struct STypeID;

class ZHM5TutorialEventsEntity : public ZEntityImpl
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	bool m_bEnabled;
	bool m_bFired_AttentionGaugeActivated : 1;
	bool m_bFired_StartedTrespassing : 1;
	bool m_bFired_CoverActivated : 1;
	bool m_bFired_EnterWindowFromLedge : 1;
	bool m_bFired_CoverToCover : 1;
	bool m_bFired_CoverScale : 1;
	bool m_bFired_LedgeAgilityActivated : 1;
	bool m_bFired_CoverTakedownByPlayer : 1;
	bool m_bFired_ShootingBalletTag : 1;
	bool m_bFired_ShootingBalletExecute : 1;
	bool m_bFired_PullVictimPossible : 1;
	bool m_bTossAimToggle : 1;
	bool m_bFired_TossFire : 1;
	bool m_bFired_UsedFibreWire : 1;
	bool m_bFired_PickedUpCloseCombatProp : 1;
	bool m_bFired_SneakInputPressed : 1;
	bool m_bFired_RunInputPressed : 1;
	bool m_bFired_InstinctPressed : 1;
	bool m_bFired_InstinctReleased : 1;
	bool m_bCanExitCover : 1;
	bool m_bCanExitCoverOnlyForSBHack : 1;
	bool m_bFakeCloseCombatButtonPress : 1;
	bool m_bFakeCoverTakedownButtonPress : 1;
	bool m_bFakePushVictimButtonPress : 1;
	bool m_bLockLedgeMovementVer : 1;
	bool m_bLockLedgeMovementHor : 1;
	bool m_bIsGod : 1;
	bool m_bShowButtonsInSB : 1;
	bool m_bBurnInstinctInSB : 1;
	bool m_bBurnInstinctOnSBTag : 1;
	bool m_bCanExitSafeZone : 1;
	bool m_bActionOrientationActive : 1;
	bool m_bHairTrigger : 1;
	bool m_bCloseCombatSlowDownActivated : 1;
	bool m_bFired_LastWitnessKilled : 1;
	bool m_bLastWitnessKilled : 1;
	float m_fCurTimeMultiplier;
	float m_fDesiredTimeMultiplier;

	static SComponentMapEntry s_componentMap[0];
	static unsigned int m_snAttentionGaugeActivated;
	static unsigned int m_snStartedTrespassing;
	static unsigned int m_snStartedEnterWindowFromLedge;
	static unsigned int m_snCoverActivated;
	static unsigned int m_snCoverToCover;
	static unsigned int m_snCoverScale;
	static unsigned int m_snLedgeAgilityActivated;
	static unsigned int m_snCoverTakedownByPlayer;
	static unsigned int m_snShootingBalletTag;
	static unsigned int m_snShootingBalletExecute;
	static unsigned int m_snPullVictimPossible;
	static unsigned int m_snTossAimToggle;
	static unsigned int m_snTossFire;
	static unsigned int m_snLockedLedgeMovementVer;
	static unsigned int m_snUnlockedLedgeMovementVer;
	static unsigned int m_snLockedLedgeMovementHor;
	static unsigned int m_snUnlockedLedgeMovementHor;
	static unsigned int m_snUsedFibreWire;
	static unsigned int m_snPickedUpCloseCombatProp;
	static unsigned int m_snSneakInputPressed;
	static unsigned int m_snRunInputPressed;
	static unsigned int m_snInstinctPressed;
	static unsigned int m_snInstinctReleased;
	static unsigned int m_snOnActivateCloseCombatStart;
	static unsigned int m_snOnActivateTakeCover;
	static unsigned int m_snOnActivateCoverTakedown;
	static unsigned int m_snOnActivatePushVictim;
	static unsigned int m_snOnActivateSlowDown;
	static unsigned int m_snOnDeactivateSlowDown;
	static unsigned int m_snOnActivateCloseCombatSlowDown;
	static unsigned int m_snOnDeactivateCloseCombatSlowDown;
	static unsigned int m_snOnForceCameraToLeftShoulder;
	static unsigned int m_snOnForceCameraToRightShoulder;
	static unsigned int m_snOnActivateActionOrientation;
	static unsigned int m_snOnDeactivateActionOrientation;
	static unsigned int m_snOnActivateGod;
	static unsigned int m_snOnDeactivateGod;
	static unsigned int m_snHairtrigger;
	static unsigned int m_snOnLastWitnessKilled;

	~ZHM5TutorialEventsEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Init() override;
	void Start() override;
	virtual void FrameUpdate(const SGameUpdateEvent& updateEvent);

	ZHM5TutorialEventsEntity() = default;
	static void RegisterType();
	ZHM5TutorialEventsEntity(ZComponentCreateInfo& pInfo);
	void OnEnable();
	void OnDisable();
	void OnReset();
	void OnResetInstinct();
	void OnResetCoverActivated();
	void OnResetAttentionGauge();
	void OnResetSneakInputPressed();
	void OnExitCoverAllowed();
	void OnExitCoverNotAllowed();
	bool CanExitCover() const;
	void OnOverrideExitCoverAllowedOnlyForSB();
	void OnOverrideExitCoverNotAllowedOnlyForSB();
	void OnCameraPanAllowed();
	void OnCameraPanLocked();
	void OnMovementAllowed();
	void OnMovementLocked();
	void OnLockLedgeMovementVer();
	void OnUnlockLedgeMovementVer();
	void OnLockLedgeMovementHor();
	void OnUnlockLedgeMovementHor();
	void OnActivateCloseCombatStart();
	void OnActivateTakeCover();
	void OnActivateCoverTakedown();
	void OnActivatePushVictim();
	void OnActivateSlowDown();
	void OnDeactivateSlowDown();
	void OnActivateCloseCombatSlowDown();
	void OnDeactivateCloseCombatSlowDown();
	float GetCloseCombatSlowDownTimer(const TEntityRef<ZCharacterTemplateAspect>& pCharacter) const;
	void OnActivateGod();
	void OnDeactivateGod();
	bool IsGod() const;
	void OnActivateShowButtonsInSB();
	void OnDeactivateShowButtonsInSB();
	bool ShowButtonsInSB() const;
	void OnActivateBurnInstinctInSB();
	void OnDeactivateBurnInstinctInSB();
	void OnActivateBurnInstinctOnSBTag();
	void OnDeactivateBurnInstinctOnSBTag();
	void OnActivateExitSafeZone();
	void OnDeactivateExitSafeZone();
	void OnForceCameraToLeftShoulder();
	void OnForceCameraToRightShoulder();
	void OnActivateActionOrientation();
	void OnDeactivateActionOrientation();
	bool HaveActionOrientationCheck() const;
	bool BurnInstinctInSB() const;
	bool CanExitSafeZone() const;
	bool FakeCloseCombatButtonPress();
	bool FakeCoverTakedownButtonPress();
	bool FakePushVictimButtonPress();
	bool LockLedgeMovementVer() const;
	bool LockLedgeMovementHor() const;
	void LastWitnessKilledEventHandler();
	TEntityRef<ZHitman5> Hitman() const;
	void ClearSignalFlags();
};
