#pragma once

#include "SClosestActorInfo.h"
#include "SActorCounts.h"
#include "EGameTension.h"
#include "TEntityRef.h"
#include "ZGameTime.h"

class IHM5Outfit;
class ZActor;
template <class T> class TMaxArrayRef;

class ZAIGameState
{
public:
	SClosestActorInfo m_ActorInfo;
	float m_fDisguiseHealth;
	TEntityRef<IHM5Outfit> m_pCurrentOutfit;
	SActorCounts m_ActorCounts;
	EGameTension m_eGameTension;
	EGameTension m_eGameTensionGuard;
	EGameTension m_eGameTensionCivilian;
	int m_nAliveEnemyCount;
	int m_nAliveGuardCount;
	ZGameTime m_nLastBulletFlyByEventTime;
	float m_fAttentionMax;
	float m_fAttentionMaxPan;
	TEntityRef<ZActor> m_pAttentionMaxActor;
	float m_fTrespassingAttentionMax;
	float m_fTrespassingAttentionMaxPan;
	TEntityRef<ZActor> m_pTrespassingAttentionMaxActor;
	float m_fDisguiseAttentionMax;
	float m_fDisguiseAttentionMaxPan;
	TEntityRef<ZActor> m_pDisguiseAttentionMaxActor;
	float m_fDisguiseHeat;
	float m_fDisguiseHeatPan;
	bool m_bDisguiseSameOutfit;
	int m_nDisguiseHeatRating;
	TEntityRef<ZActor> m_pDisguiseHeatActor;
	ZGameTime m_tLastCiviliansGotHelpEvent;

	union 
	{
		unsigned int unionInt;

		struct 
		{
			bool m_bOutfitBroken : 1;
			bool m_bOutfitSuspicious : 1;
			bool m_bInDisguise : 1;
			bool m_bHitmanInCombat : 1;
			bool m_bBulletFlyBy : 1;
			bool m_bIsHitmanStealthKilling : 1;
			bool m_bHitmanTrespassing : 1;
			bool m_bHitmanDeepTrespassing : 1;
			bool m_bHitmanNearDeadBody : 1;
			bool m_bHitmanIllegalWeapon : 1;
			bool m_bHitmanChangingOutfit : 1;
			bool m_bAttentionOSDVisible : 1;
			bool m_bBodyFound : 1;
			bool m_bBloodPoolFound : 1;
			bool m_bCanOpenCPDoor : 1;
			bool m_bIsHitmanHunted : 1;
			bool m_bSpottedEnteringCloset : 1;
			bool m_bAnyGuardsAlive : 1;
		};
	};

	ZAIGameState() = default;
	bool GetHitmanInCombat() const;
	bool GetHitmanTrespassing() const;
	bool GetHitmanDeepTrespassing() const;
	bool GetHitmanIllegalWeapon() const;
	bool GetHitmanNearDeadBody() const;
	ZGameTime GetCivilansGotHelpTime() const;
	void ResetPerFrameStates();
	void SetBulletFlyByHitman(bool bFlyBy);
	void SetStealthKill(bool bStealthKill);
	void SetActorDist(const SClosestActorInfo& info);
	void SetEnemies(TMaxArrayRef<TEntityRef<ZActor>>& enemies);
	bool IsHitmanIsHunted() const;
	EGameTension GetGameTension() const;
	void SetGameTension(EGameTension tension);
	void SetGameTensionGuard(EGameTension tension);
	void SetGameTensionCivilian(EGameTension tension);
	bool GetCanCPDoorsOpen() const;
	bool GetCanForwardSpawnBeUsed() const;
	float GetMaxDisguiseAttention() const;
	void SetActorCount(const SActorCounts& counts);
	void SetDisguise(TEntityRef<IHM5Outfit> pOutfit, bool bOutfitSuspicious, bool bBroken, bool bInDisguise);
	float GetDisguiseHealth() const;
	void SetDisguiseHealth(float fDisguiseHealth);
	void SetBodyFound(bool bBodyFound);
	void SetBloodPoolFound(bool bBloodPoolFound);
	void SetCiviliansGotHelp(bool b);
	void SetAttentionOSDVisible(bool bVisible);
	bool GetAttentionOSDVisible() const;
	bool LastEnemyDiedThisFrame(const ZAIGameState& oldState) const;
	bool IsCurrentOutfitBroken() const;
	bool IsCurrentOutfitSuspicious() const;
	~ZAIGameState() = default;
	ZAIGameState& operator=(const ZAIGameState& __that);
};
