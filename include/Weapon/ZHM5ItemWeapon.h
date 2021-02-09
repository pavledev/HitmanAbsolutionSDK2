#pragma once

#include "ZHM5Item.h"
#include "IHM5ItemWeapon.h"
#include "ZHM5WeaponBasicConfigEntity.h"
#include "IParticleEmitterEntity.h"
#include "ZHM5WeaponSoundSetupEntity.h"
#include "ISoundDefinition.h"
#include "ZHM5ProjectilePool.h"
#include "ZHM5WeaponConfigurator.h"

class alignas(16) ZHM5ItemWeapon : public ZHM5Item, public IHM5ItemWeapon
{
public:
    TEntityRef<ZHM5WeaponBasicConfigEntity> m_BasicConfigEntity;
    ZEntityRef m_AmmoProperties;
    bool m_bSemiAutoOperation;
    bool m_bFullAutoOperation;
    int m_nShotsPerMinute;
    int m_nNPCShotsPerMinute;
    int m_nNPCShotsPerMinuteVariance;
    float m_fMuzzleVelocity;
    float m_fCloseRange;
    float m_fNearRange;
    float m_fMediumRange;
    float m_fFarRange;
    float m_fAINearCombatRange;
    float m_fAIFarCombatRange;
    float m_fDamageMultiplier;
    float m_fReloadFactor;
    float m_fMuzzleEnergyMultiplier;
    eWeaponType m_WeaponType;
    ZRuntimeResourceID m_ridClipTemplate;
    float m_fImpactForce;
    float m_fRagdollImpactForce;
    float m_fRagdollImpactUpKick;
    EWeaponAnimationCategory m_eAnimationCategory;
    ZEntityRef m_pVariationResource;
    EHM5SoundBulletType m_eSoundBulletType;
    float m_fNPCDamageMultiplier;
    ZEntityRef m_MuzzleExit;
    ZEntityRef m_MuzzleFlash;
    ZEntityRef m_MuzzleSmoke;
    ZEntityRef m_Light;
    ZEntityRef m_CartridgeEject;
    float m_fCartridgeEjectForceMultiplier;
    TEntityRef<IParticleEmitterEntity> m_MuzzleFlashEffect;
    TEntityRef<IParticleEmitterEntity> m_MuzzleSmokeEffect;
    TEntityRef<ISequenceEntity> m_LightEffect;
    float m_fSilencerGFXOffset;
    bool m_fHitmanAutoreload;
    float m_fPrecisionMinDegree;
    float m_fPrecisionMaxDegree;
    float m_fPrecisionTime;
    int m_fPrecisionNumBullets;
    float m_fPrecisionRecoveryTime;
    float m_fPrecisionRecoverySpeed;
    float m_fPrecisionRecoveryDelay;
    float m_fOTSCamPrecisionModifier;
    float m_fStandNotMovingPrecisionModifier;
    float m_fStandMovingPrecisionModifier;
    float m_fSneakNotMovingPrecisionModifier;
    float m_fSneakMovingPrecisionModifier;
    float m_fBlindfirePrecisionModifier;
    float m_fCoverPrecisionModifier;
    float m_fScopeModePrecisionDegree;
    float m_fPrecisionShotMultiplier;
    float m_fCrosshairOffset;
    float m_fCrosshairScale;
    float m_fRecoilX;
    float m_fRecoilZ;
    float m_fRecoilVertialRange;
    float m_fRecoilHorizontalRange;
    float m_fRecoilDelay;
    float m_fRecoilRecoveryDelay;
    float m_fRecoilRecoverySpeed;
    float m_fRecoilEaseTime;
    float m_fRecoilMax;
    bool m_bScopedWeapon;
    ZEntityRef m_ScopePosition;
    TArray<SVector2> m_aScopeZoom;
    float m_fScopeFOV;
    SVector3 m_vBobbingAngleX;
    SVector3 m_vBobbingAngleY;
    SVector3 m_vBobbingFrequencyX;
    SVector3 m_vBobbingFrequencyY;
    float m_fPulseIncreaseOnShooting;
    float m_fDragCorrectionFraction;
    float m_fDragCorrectionTime;
    SVector2 m_vDragAngles;
    float m_fZRecoilDistance;
    float m_fZRecoilTime;
    float m_fCounterRotationFactor;
    ZEntityRef m_ScopeCrossHair;
    TEntityRef<ZHM5WeaponSoundSetupEntity> m_SoundSetup;
    TEntityRef<ISoundDefinition> m_SoundDefinitionEntity;
    TEntityRef<ZHM5WeaponHandPosBox> m_LeftHandPos;
    ZRuntimeResourceID m_EquippedMaterial;
    ZHM5ProjectilePool m_ProjectilePool;
    ZHM5WeaponConfigurator m_Configurator;
    ZSpatialEntity* m_pMuzzleExit;
    ZSpatialEntity* m_pMuzzleFlash;
    ZSpatialEntity* m_pMuzzleSmoke;
    ZSpatialEntity* m_pLight;
    ZSpatialEntity* m_pCartridgeEject;
    IHM5AmmoProperties* m_pAmmoProperties;
    eWeaponOperation m_CurrentWeaponOperation;
    int m_nWeaponOperationBitmask;
    float4 m_vTargetPos;
    unsigned __int16 m_nBulletsToFire;
    unsigned __int16 m_nMinNumOfBulletsToFire;
    unsigned __int16 m_nBulletsFired;
    unsigned __int16 m_nBulletsInMagazine;
    unsigned __int16 m_nBulletsBeforeAmmoSuck;
    unsigned __int16 m_iBulletsSinceLastTracer;
    unsigned __int16 m_nAIReloadPercentage;
    ZGameTime m_tLastShootTime;
    float m_fTimeBetweenShots;
    float m_fNPCTimeBetweenShots;
    float m_fPrecisionFactor;
    unsigned int m_nFrameNumber;
    SMatrix43 m_mvPreCartridgeEjectMatPos;
    float m_fFirstShotPrecision;
    __int8 m_bFrmUpdateActive : 1;
    __int8 m_bFireStarted : 1;
    __int8 m_bFireEndRequested : 1;
    __int8 m_bCanPlayEmptySound : 1;
    __int8 m_bSupressWeaponEquippedSignal : 1;
    __int8 m_bUseAlternateFire : 1;
    __int8 m_bAllowActorHitActor : 1;
    __int8 m_bAllowAIEvents : 1;
    __int8 m_bWaitingForUpgradesRefresh : 1;
    __int8 m_bAttemptMarkAsPickedUp : 1;
    __int8 m_bPendingChangeAlternateFire : 1;
    __int8 m_bInitialInventoryBulletsGiven : 1;
    __int8 m_bInitialClipBulletsGiven : 1;

    virtual void OnPrecisionRecovered();
    virtual float GetPrecisionMaxDegree();
    virtual float GetPrecisionTime();
    virtual void SignalClipEmpty();
    virtual float GetRecoilDelay();
    virtual float GetRecoilRecoveryDelay();
    virtual float GetRecoilHorizontalRange();
    virtual float GetRecoilVerticalRange();
    virtual float GetRecoilRecoverySpeed();
    virtual float GetRecoilMax();
    virtual float GetRecoilEaseTime();
    virtual void ToggleAlternateFireDeferred();
};
