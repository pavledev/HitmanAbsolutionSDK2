#pragma once

#include "ZHM5SBTag.h"
#include "SHM5SBShared.h"
#include "ESBTagMode.h"
#include "SCharacterTagInfo.h"

class ZHM5SBTagMode
{
public:
	enum ETagReturn
	{
		eTagging = 0,
		eStartSB = 1,
		eCancelSB = 2
	};

	struct SCharacterTagInfo
	{
		const ZLinkedEntity* m_pCharacter;
		float m_fAccumulatedDamage;

		SCharacterTagInfo() = default;
	};

	ZHM5SBTag m_aTags[32];
	unsigned int m_nNumTags;
	unsigned int m_nMaxNumTags;
	TArray<ZHM5SBTag> m_aUntaggableActorTags;
	bool m_bZoom;
	bool m_bTriggerAimAssist;
	bool m_bLastTag;
	bool m_bPropCostOverride;
	float m_fPropCost;
	float m_fFocalDist;
	float m_fWeaponMinFractionBetweenTags;
	float m_fAutoModeFireRate;
	float m_fTagTimeAutoMode;
	unsigned int m_nNumAutoShotsMade;
	const SHM5SBShared& m_SBShared;
	bool m_bCanTag;
	TEntityRef<IHM5ItemWeapon> m_arWeapons[2];
	unsigned int m_anStartAmmo[2];
	ESBTagMode m_eTagMode;
	TFixedArray<SCharacterTagInfo, 32> m_aHitCharacters;
	unsigned int m_nHitCharacters;
	SAimCandidate m_LastCandidate;
	TArray<float4> m_ArcPositions;
	bool m_bLookAtPosInitialized;
	float4 m_vLookAtPos;
	float4 m_vLookAtDir;
	bool m_bAllowPlayerToExecute;
	bool m_bExecuteWhenInstinctRunsOut;

	static const unsigned int INVALID_TAG;

	ZHM5SBTagMode() = default;
	ZHM5SBTagMode(const SHM5SBShared& SBShared);
	ETagReturn Update(float fDeltaTime, bool bEndTagging, bool bForceStart);
	void Start(ESBTagMode eSBTagMode, bool bAllowPlayerToExecute, bool bExecuteWhenInstinctRunsOut);
	void TagFiredAt(unsigned int nIndex);
	void HideTag(unsigned int nIndex);
	bool CanTag() const;
	float GetShotFraction(float fExecutionFraction) const;
	bool KilledAllTaggedCharacters() const;
	bool TriggerAimAssist() const;
	bool IsZoomed() const;
	void EnablePropTaggingCostOverride(float fixedDamageCost);
	void DisablePropTaggingCostOverride();
	bool IsPropTaggingCostOverrideSet();
	void ConfirmKill(unsigned int nIndex);
	void OnChainReactionHit(ZActor* pActor, unsigned int nIndex);
	TArrayEnumerator<ZHM5SBTag const> GetUntaggableActorsEnumerator() const;
	unsigned int GetFirstNotFired() const;
	const ZHM5SBTag& GetTag(unsigned int nIndex) const;
	unsigned int GetNumTags() const;
	unsigned int GetFirstNotFiredOnNPC() const;
	unsigned int GetLastFired() const;
	float4 GetLookAtPos() const;
	bool AllTagsExecuted() const;
	float GetTagFraction(unsigned int nTagIndex, float fExecutionFraction) const;
	void Sort(const TEntityRef<ZActor> rPrimaryTarget);
	float GetFractionBetweenTags() const;
	TEntityRef<ZHM5BaseCharacter> FindParentCharacter(TEntityRef<ZSpatialEntity> rSpatial);
	void UpdateCursor(float fDeltaTime);
	void UpdateTag(float fDeltaTime);
	void FindShotPos(const SAimCandidate* pTarget);
	void RestoreGlowingOnLinkedEntities();
	void InsertTarget(ZHM5SBTag& Target);
	void RemoveTag();
	void UpdateWeaponAmmo();
	void GetRay(float4& vOrigo, float4& vDir);
	float4 OffsetTagDir(const float4& vTagDir) const;
	void UpdateTagModeLookAtPoint(float fLookAtDist, float fDeltaTime);
	void RestoreWeaponAmmo();
	float AccumulateDamage(const ZLinkedEntity* pLinked, float fDamage);
	float ReduceDamage(const ZLinkedEntity* pLinked, float fDamage);
	void RemoveActorKillTags();
	SCharacterTagInfo* GetCharacterTagInfo(const ZLinkedEntity* pLinked, bool bCreate);
	~ZHM5SBTagMode() = default;
};
