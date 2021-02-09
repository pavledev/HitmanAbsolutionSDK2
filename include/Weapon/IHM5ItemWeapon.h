#pragma once

#include "IComponentInterface.h"
#include "ZEntityRef.h"
#include "IHM5AmmoProperties.h"
#include "eWeaponOperation.h"
#include "float4.h"
#include "SMatrix43.h"
#include "eWeaponType.h"
#include "eItemType.h"
#include "EWeaponAnimationCategory.h"
#include "SHM5ScopeParameters.h"
#include "TEntityRef.h"
#include "ZHM5WeaponHandPosBox.h"
#include "IHM5Item.h"
#include "EHM5SoundBulletType.h"
#include "EHM5DeadlyThrowType.h"
#include "EActorDeathType.h"
#include "SHM5WeaponConfig.h"

class IHM5ItemWeapon : public IComponentInterface
{
public:
    virtual void OnHitmanReloadWeapon();
    virtual void OnHitmanReloadFraction(float, const ZString*, bool, const float);
    virtual void OnHitmanRecoilTime(float, const ZString*);
    virtual void OnHitmanPointShootingFraction(float, const ZString*);
    virtual const ZEntityRef* GetWeaponVariationResource(const ZEntityRef* result);
    virtual IHM5AmmoProperties* GetAmmoProperties();
    virtual bool IsFiring();
    virtual bool SetWeaponOperation(eWeaponOperation weaponOperation, bool bForce);
    virtual float GetAINearCombatRange();
    virtual float GetAIFarCombatRange();
    virtual void SetTargetPos(const float4*);
    virtual bool StartFire(float fFirstShotPrecision);
    virtual bool EndFire();
    virtual void OnFireWeaponRelease();
    virtual SMatrix43* GetMuzzleExitRootMatPos(SMatrix43* result);
    virtual SMatrix43* GetMuzzleFlashRootMatPos(SMatrix43* result);
    virtual SMatrix43* GetMuzzleSmokeRootMatPos(SMatrix43* result);
    virtual SMatrix43* GetMuzzleLightRootMatPos(SMatrix43* result);
    virtual SMatrix43* GetCartridgeEjectRootMatPos(SMatrix43* result);
    virtual SMatrix43* GetLeftHandTransform(SMatrix43* result);
    virtual void SetBulletsInMagazine(int);
    virtual unsigned __int16 GetBulletsInMagazine();
    virtual int GetBulletsBeforeAmmoSuck();
    virtual void UpdateBulletsBeforeAmmoSuck(bool);
    virtual float4* GetTargetPos(float4* result);
    virtual float GetMuzzleVelocity();
    virtual bool IsCurrentClipLowOnAmmo();
    virtual float GetPrecisionDegree(float);
    virtual void GetCrossHairFactors(float*, float*);
    virtual float CalcPrecisionDegree();
    virtual float GetOTSCamPrecisionModifier();
    virtual float GetStandNotMovingPrecisionModifier();
    virtual float GetStandMovingPrecisionModifier();
    virtual float GetSneakNotMovingPrecisionModifier();
    virtual float GetSneakMovingPrecisionModifier();
    virtual float GetBlindfirePrecisionModifier();
    virtual float GetPrecisionShotMultiplier();
    virtual float GetPrecisionFactor();
    virtual void SetPrecisionFactor(float);
    virtual eWeaponOperation GetCurrentWeaponOperation();
    virtual float GetDamageMultiplier();
    virtual float GetMuzzleEnergyMultiplier();
    virtual bool GetFiringStarted();
    virtual bool IsHandGun();
    virtual bool IsRevolver();
    virtual bool IsSmg();
    virtual bool IsRifle();
    virtual bool IsRPG();
    virtual bool IsSniper();
    virtual bool IsShotgun();
    virtual bool IsFireArm();
    virtual bool IsProjectileWeapon();
    virtual bool IsCloseCombatWeapon();
    virtual eWeaponType GetWeaponType();
    virtual eItemType GetItemType();
    virtual EWeaponAnimationCategory GetAnimationCategory();
    virtual void PlayShotEffect(bool, int);
    virtual void PlayReleaseTriggerSound();
    virtual void PlayEmptySound(bool);
    virtual void PlayFireAnimation(bool);
    virtual bool HasScope();
    virtual void ImmediateReload();
    virtual void SetAIReloadPercentage(unsigned __int16);
    virtual bool NeedReloading();
    virtual void GetScopeParameters(SHM5ScopeParameters*);
    virtual void ShowScopeRenderDestination(bool);
    virtual void SupressWeaponEquippedSignal();
    virtual SVector2 GetRecoil();
    virtual float4* CreateProjectileVector(float4* result, const float4*, const float4*, float);
    virtual TEntityRef<ZHM5WeaponHandPosBox>* GetLeftHandPos(TEntityRef<ZHM5WeaponHandPosBox>* result);
    virtual float GetImpactForce();
    virtual float GetRagdollImpactForce();
    virtual float GetRagdollImpactUpKick();
    virtual bool IsSameType(const TEntityRef<IHM5Item>);
    virtual bool HasAlternativeFire();
    virtual void ToggleAlternateFire();
    virtual bool UseAlternateFire();
    virtual bool IsTurnedOn();
    virtual EHM5SoundBulletType GetSoundBulletType();
    virtual void OnWeaponEquipped();
    virtual void OnWeaponUnEquipped();
    virtual void OnWeaponPlayerEquipped();
    virtual void OnWeaponPlayerUnEquipped();
    virtual void OnWeaponPlayerSwapped();
    virtual void OnCloseCombatImpact(bool, bool, const ZEntityRef*);
    virtual void OnDeadlyThrowImpact();
    virtual bool IsFiberwire();
    virtual EHM5DeadlyThrowType GetDeadlyThrowType();
    virtual bool IsPropUsable();
    virtual bool IsRemoteControlled();
    virtual EActorDeathType GetActorDeathType(bool);
    virtual const SHM5WeaponConfig* GetConfig();
    virtual ZRuntimeResourceID* GetEquippedMaterialResource(ZRuntimeResourceID* result);
    virtual bool IsAutoreloadEnabled();
    virtual bool IsBroken();
    virtual bool IsForcePickupDisabled();
};
