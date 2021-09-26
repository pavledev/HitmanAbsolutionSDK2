#pragma once

#include "ZHM5Item.h"
#include "IHM5ItemWeapon.h"
#include "ECCWeaponAnimSet.h"
#include "SActorSoundDefs.h"
#include "SCCEffectSet.h"
#include "EActorDeathType.h"
#include "EHM5SoundBulletType.h"
#include "EWeaponAnimationCategory.h"
#include "SComponentMapEntry.h"
#include "SMatrix43.h"
#include "TArray.h"
#include "TEntityRef.h"
#include "ZEntityRef.h"
#include "ZRuntimeResourceID.h"
#include "ZVariantRef.h"
#include "eItemType.h"
#include "eWeaponOperation.h"
#include "eWeaponType.h"
#include "float4.h"

class IHM5AmmoProperties;
class IHM5Item;
class ZCCEffectSetEntity;
class ZComponentCreateInfo;
class ZHM5Action;
class ZHM5WeaponHandPosBox;
class ZString;
struct SCollisionInfo;
struct SHM5ScopeParameters;
struct SHM5WeaponConfig;
struct STypeID;

class ZHM5ItemCCWeapon : public ZHM5Item, public IHM5ItemWeapon
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	enum EUseTypes
	{
		EUT_CantUse = 0,
		EUT_Toggle = 1,
		EUT_TurnOn = 2
	};

	TEntityRef<ZHM5Action> m_pUseAction;
	EUseTypes m_eUseType;
	ECCWeaponAnimSet m_eAnimSetFrontSide;
	ECCWeaponAnimSet m_eAnimSetBack;
	TArray<TEntityRef<ZCCEffectSetEntity>> m_aEffectSetsFrontSide;
	TArray<TEntityRef<ZCCEffectSetEntity>> m_aEffectSetsBack;
	SActorSoundDefs::EDefinition m_eDeathSpeakFront;
	SActorSoundDefs::EDefinition m_eDeathSpeakBack;
	SActorSoundDefs::EDefinition m_eReactionSpeak;
	EActorDeathType m_eDeathTypeFront;
	EActorDeathType m_eDeathTypeBack;
	ZEntityRef m_pVariationResource;
	int m_nLifeSpan;
	bool m_bPercievedAsWeapon;
	ZRuntimeResourceID m_EquippedMaterial;
	bool m_bCountsAsFiberWire;
	IHM5ItemWeapon::EHM5DeadlyThrowType m_eDeadlyThrowTypeFiberWire;
	unsigned short m_nImpactCount;
	bool m_bTurnedOn : 1;
	bool m_bBroken : 1;
	bool m_bForcePickupDisabled : 1;

	static SComponentMapEntry s_componentMap[0];
	static const SHM5WeaponConfig s_EmptyConfig;
	static unsigned int m_snImpactFrontSide;
	static unsigned int m_snImpactBack;
	static unsigned int m_snThrowImpact;
	static unsigned int m_snEquipped;
	static unsigned int m_snUnequipped;
	static unsigned int m_snOnTurnOn;
	static unsigned int m_snOnTurnOff;
	static unsigned int m_snOnWeaponBroken;
	static unsigned int m_snBreakWeaponOnTarget;
	static unsigned int m_snDeadlyThrowImpact;
	static unsigned int m_snWeaponPlayerEquipped;
	static unsigned int m_snWeaponPlayerUnEquipped;
	static unsigned int m_snWeaponSwapped;

	~ZHM5ItemCCWeapon() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Activate(const ZString& sSubset) override;
	void Deactivate(const ZString& sSubset) override;
	void Init() override;
	void ResourceChanged() override;
	void OnThrowImpact(const SCollisionInfo& collInfo) override;
	virtual void SetAIBurstCount(int nBurstCount);
	virtual bool Reload();
	virtual bool IsReloading() const;
	virtual void OnImpact(const ZEntityRef& pHitTarget);
	virtual void TurnOn();
	virtual void TurnOff();

	eItemType GetItemType() const override;
	void OnAttachItem(const ZEntityRef& pOwner) override;
	void OnThrowItem(const float4& vVelocity, const float4& vPos) override;
	void EnablePickup(bool bEnable) override;
	bool IsPercievedAsWeapon() const override;

	void OnHitmanReloadWeapon() override;
	void OnHitmanReloadFraction(float fFraction, const ZString& strAnimName, bool bAborted, const float fAbortTime) override;
	void OnHitmanRecoilTime(float fRecoilTime, const ZString& strAnimName) override;
	void OnHitmanPointShootingFraction(float fFraction, const ZString& strAnimName) override;
	const ZEntityRef GetWeaponVariationResource() const override;
	IHM5AmmoProperties* GetAmmoProperties() const override;
	bool IsFiring() const override;
	bool SetWeaponOperation(eWeaponOperation wOp, bool bForce) override;
	float GetAINearCombatRange() override;
	float GetAIFarCombatRange() override;
	void SetTargetPos(const float4& vTargetPos) override;
	bool StartFire(float fFirstShotPrecision) override;
	bool EndFire() override;
	void OnFireWeaponRelease() override;
	SMatrix43 GetMuzzleExitRootMatPos() const override;
	SMatrix43 GetMuzzleFlashRootMatPos() override;
	SMatrix43 GetMuzzleSmokeRootMatPos() override;
	SMatrix43 GetMuzzleLightRootMatPos() override;
	SMatrix43 GetCartridgeEjectRootMatPos() override;
	SMatrix43 GetLeftHandTransform() override;
	void SetBulletsInMagazine(int nBullets) override;
	unsigned short GetBulletsInMagazine() const override;
	int GetBulletsBeforeAmmoSuck() const override;
	void UpdateBulletsBeforeAmmoSuck(bool bReset) override;
	float4 GetTargetPos() override;
	float GetMuzzleVelocity() override;
	bool IsCurrentClipLowOnAmmo() const override;
	float GetPrecisionDegree(float fPrecisionShotPrc) const override;
	void GetCrossHairFactors(float& fOffset, float& fScaling) const override;
	float CalcPrecisionDegree() const override;
	float GetOTSCamPrecisionModifier() const override;
	float GetStandNotMovingPrecisionModifier() const override;
	float GetStandMovingPrecisionModifier() const override;
	float GetSneakNotMovingPrecisionModifier() const override;
	float GetSneakMovingPrecisionModifier() const override;
	float GetBlindfirePrecisionModifier() const override;
	float GetPrecisionShotMultiplier() const override;
	float GetPrecisionFactor() const override;
	void SetPrecisionFactor(float fPrecisionFactor) override;
	eWeaponOperation GetCurrentWeaponOperation() const override;
	float GetDamageMultiplier() const override;
	float GetMuzzleEnergyMultiplier() const override;
	bool GetFiringStarted() const override;
	bool IsHandGun() const override;
	bool IsRevolver() const override;
	bool IsSmg() const override;
	bool IsRifle() const override;
	bool IsRPG() const override;
	bool IsSniper() const override;
	bool IsShotgun() const override;
	bool IsFireArm() const override;
	bool IsProjectileWeapon() const override;
	bool IsCloseCombatWeapon() const override;
	eWeaponType GetWeaponType() const override;
	EWeaponAnimationCategory GetAnimationCategory() const override;
	void PlayShotEffect(bool bExternal, int nBulletsFired) override;
	void PlayReleaseTriggerSound() override;
	void PlayEmptySound(bool bExternal) override;
	void PlayFireAnimation(bool bFinal) override;
	bool HasScope() const override;
	void ImmediateReload() override;
	void SetAIReloadPercentage(unsigned short nPercentage) override;
	bool NeedReloading() const override;
	void GetScopeParameters(SHM5ScopeParameters& ScopeParameters) const override;
	void ShowScopeRenderDestination(bool bShow) override;
	void SupressWeaponEquippedSignal() override;
	float4 CreateProjectileVector(const float4& vProjectileStartPosition, const float4& vTargetPosition, float fPrecisionPrct) const override;
	TEntityRef<ZHM5WeaponHandPosBox> GetLeftHandPos() const override;
	float GetImpactForce() const override;
	float GetRagdollImpactForce() const override;
	float GetRagdollImpactUpKick() const override;
	bool IsSameType(const TEntityRef<IHM5Item> rItem) const override;
	bool HasAlternativeFire() const override;
	void ToggleAlternateFire() override;
	bool UseAlternateFire() const override;
	bool IsTurnedOn() const override;
	EHM5SoundBulletType GetSoundBulletType() const override;
	void OnWeaponEquipped() override;
	void OnWeaponUnEquipped() override;
	void OnWeaponPlayerEquipped() override;
	void OnWeaponPlayerUnEquipped() override;
	void OnWeaponPlayerSwapped() override;
	void OnCloseCombatImpact(bool bBehind, bool bLastImpact, const ZEntityRef& pHitTarget) override;
	void OnDeadlyThrowImpact() override;
	bool IsFiberwire() const override;
	IHM5ItemWeapon::EHM5DeadlyThrowType GetDeadlyThrowType() const override;
	bool IsPropUsable() const override;
	bool IsRemoteControlled() const override;
	EActorDeathType GetActorDeathType(bool bFront) const override;
	const SHM5WeaponConfig& GetConfig() const override;
	ZRuntimeResourceID GetEquippedMaterialResource() const override;
	bool IsAutoreloadEnabled() const override;
	bool IsBroken() const override;
	bool IsForcePickupDisabled() const override;

	ZHM5ItemCCWeapon() = default;
	static void RegisterType();
	ZHM5ItemCCWeapon(ZComponentCreateInfo& pInfo);
	void EmmitGameStateSignals();
	void RemoteDetonate();
	void SetImpactCount(unsigned short nImpactCount);
	short GetImpactCount() const;
	ECCWeaponAnimSet GetAnimSetFrontSide();
	ECCWeaponAnimSet GetAnimSetBack();
	SCCEffectSet GetEffectSet(unsigned int nEvent, bool bBackSet);
	SActorSoundDefs::EDefinition GetDeathSpeakFront();
	SActorSoundDefs::EDefinition GetDeathSpeakBack();
	SActorSoundDefs::EDefinition GetReactionSpeak();
	void OnTurnOn();
	void OnTurnOff();
	void OnToggleOnOff();
	void OnWeaponBroken();
	void OnDisablePickup();
	void OnWeaponBrokenInternal(const ZEntityRef& pHitTarget);
	void UpdateUseAction();
};
