#pragma once

#include "IComponentInterface.h"
#include "ZEntityRef.h"
#include "eWeaponOperation.h"
#include "float4.h"
#include "SMatrix43.h"
#include "eWeaponType.h"
#include "eItemType.h"
#include "EWeaponAnimationCategory.h"
#include "TEntityRef.h"
#include "EHM5SoundBulletType.h"
#include "EActorDeathType.h"
#include "SVector2.h"
#include "ZRuntimeResourceID.h"

class IHM5AmmoProperties;
class IHM5Item;
class ZHM5WeaponHandPosBox;
class ZString;
struct SHM5ScopeParameters;
struct SHM5WeaponConfig;

class __declspec(novtable) IHM5ItemWeapon : public IComponentInterface
{
public:
	enum EHM5DeadlyThrowType
	{
		DEADLYTHROW_NONE = 0,
		DEADLYTHROW_LIGHT = 1,
		DEADLYTHROW_HEAVY = 2
	};

	~IHM5ItemWeapon() override = default;
	virtual void OnHitmanReloadWeapon() = 0;
	virtual void OnHitmanReloadFraction(float param1, const ZString& string, bool param3, const float param4) = 0;
	virtual void OnHitmanRecoilTime(float param1, const ZString& string) = 0;
	virtual void OnHitmanPointShootingFraction(float param1, const ZString& string) = 0;
	virtual const ZEntityRef GetWeaponVariationResource() const = 0;
	virtual IHM5AmmoProperties* GetAmmoProperties() const = 0;
	virtual bool IsFiring() const = 0;
	virtual bool SetWeaponOperation(eWeaponOperation param1, bool param2) = 0;
	virtual float GetAINearCombatRange() = 0;
	virtual float GetAIFarCombatRange() = 0;
	virtual void SetTargetPos(const float4& param1) = 0;
	virtual bool StartFire(float param1) = 0;
	virtual bool EndFire() = 0;
	virtual void OnFireWeaponRelease() = 0;
	virtual SMatrix43 GetMuzzleExitRootMatPos() const = 0;
	virtual SMatrix43 GetMuzzleFlashRootMatPos() = 0;
	virtual SMatrix43 GetMuzzleSmokeRootMatPos() = 0;
	virtual SMatrix43 GetMuzzleLightRootMatPos() = 0;
	virtual SMatrix43 GetCartridgeEjectRootMatPos() = 0;
	virtual SMatrix43 GetLeftHandTransform() = 0;
	virtual void SetBulletsInMagazine(int param1) = 0;
	virtual unsigned short GetBulletsInMagazine() const = 0;
	virtual int GetBulletsBeforeAmmoSuck() const = 0;
	virtual void UpdateBulletsBeforeAmmoSuck(bool param1) = 0;
	virtual float4 GetTargetPos() = 0;
	virtual float GetMuzzleVelocity() = 0;
	virtual bool IsCurrentClipLowOnAmmo() const = 0;
	virtual float GetPrecisionDegree(float param1) const = 0;
	virtual void GetCrossHairFactors(float& param1, float& param2) const = 0;
	virtual float CalcPrecisionDegree() const = 0;
	virtual float GetOTSCamPrecisionModifier() const = 0;
	virtual float GetStandNotMovingPrecisionModifier() const = 0;
	virtual float GetStandMovingPrecisionModifier() const = 0;
	virtual float GetSneakNotMovingPrecisionModifier() const = 0;
	virtual float GetSneakMovingPrecisionModifier() const = 0;
	virtual float GetBlindfirePrecisionModifier() const = 0;
	virtual float GetPrecisionShotMultiplier() const = 0;
	virtual float GetPrecisionFactor() const = 0;
	virtual void SetPrecisionFactor(float param1) = 0;
	virtual eWeaponOperation GetCurrentWeaponOperation() const = 0;
	virtual float GetDamageMultiplier() const = 0;
	virtual float GetMuzzleEnergyMultiplier() const = 0;
	virtual bool GetFiringStarted() const = 0;
	virtual bool IsHandGun() const = 0;
	virtual bool IsRevolver() const = 0;
	virtual bool IsSmg() const = 0;
	virtual bool IsRifle() const = 0;
	virtual bool IsRPG() const = 0;
	virtual bool IsSniper() const = 0;
	virtual bool IsShotgun() const = 0;
	virtual bool IsFireArm() const = 0;
	virtual bool IsProjectileWeapon() const = 0;
	virtual bool IsCloseCombatWeapon() const = 0;
	virtual eWeaponType GetWeaponType() const = 0;
	virtual eItemType GetItemType() const = 0;
	virtual EWeaponAnimationCategory GetAnimationCategory() const = 0;
	virtual void PlayShotEffect(bool param1, int param2) = 0;
	virtual void PlayReleaseTriggerSound() = 0;
	virtual void PlayEmptySound(bool param1) = 0;
	virtual void PlayFireAnimation(bool param1) = 0;
	virtual bool HasScope() const = 0;
	virtual void ImmediateReload() = 0;
	virtual void SetAIReloadPercentage(unsigned short param1) = 0;
	virtual bool NeedReloading() const = 0;
	virtual void GetScopeParameters(SHM5ScopeParameters& scopeParameters) const = 0;
	virtual void ShowScopeRenderDestination(bool param1) = 0;
	virtual void SupressWeaponEquippedSignal() = 0;
	virtual SVector2 GetRecoil() const;
	virtual float4 CreateProjectileVector(const float4& param1, const float4& param2, float param3) const = 0;
	virtual TEntityRef<ZHM5WeaponHandPosBox> GetLeftHandPos() const = 0;
	virtual float GetImpactForce() const = 0;
	virtual float GetRagdollImpactForce() const = 0;
	virtual float GetRagdollImpactUpKick() const = 0;
	virtual bool IsSameType(const TEntityRef<IHM5Item> entityRef) const = 0;
	virtual bool HasAlternativeFire() const = 0;
	virtual void ToggleAlternateFire() = 0;
	virtual bool UseAlternateFire() const = 0;
	virtual bool IsTurnedOn() const = 0;
	virtual EHM5SoundBulletType GetSoundBulletType() const = 0;
	virtual void OnWeaponEquipped() = 0;
	virtual void OnWeaponUnEquipped() = 0;
	virtual void OnWeaponPlayerEquipped() = 0;
	virtual void OnWeaponPlayerUnEquipped() = 0;
	virtual void OnWeaponPlayerSwapped() = 0;
	virtual void OnCloseCombatImpact(bool param1, bool param2, const ZEntityRef& entityRef) = 0;
	virtual void OnDeadlyThrowImpact() = 0;
	virtual bool IsFiberwire() const = 0;
	virtual EHM5DeadlyThrowType GetDeadlyThrowType() const = 0;
	virtual bool IsPropUsable() const = 0;
	virtual bool IsRemoteControlled() const = 0;
	virtual EActorDeathType GetActorDeathType(bool param1) const = 0;
	virtual const SHM5WeaponConfig& GetConfig() const = 0;
	virtual ZRuntimeResourceID GetEquippedMaterialResource() const = 0;
	virtual bool IsAutoreloadEnabled() const = 0;
	virtual bool IsBroken() const = 0;
	virtual bool IsForcePickupDisabled() const = 0;

	static void RegisterType();
	IHM5ItemWeapon() = default;
};
