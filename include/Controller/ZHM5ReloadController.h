#pragma once

#include "TEntityRef.h"
#include "IHM5ItemWeapon.h"
#include "IMorphemeEntity.h"
#include "ZHitmanMorphemePostProcessor.h"
#include "ZHitman5.h"

class ZHM5ReloadController
{
public:
	TEntityRef<IHM5ItemWeapon> m_rWeaponToReload[2];
	TEntityRef<IMorphemeEntity> m_MorphemeEntity;
	ZMorphemeNetworkInstance* m_pMrNetwork;
	ZHitmanMorphemePostProcessor* m_PostProcessor;
	TEntityRef<ZHitman5> m_pHitman;
	bool m_bProgressReloadFraction;
	bool m_bSkipToCockingSection;
	float m_fReloadWeight;
	float m_fReloadAnimFraction;
	float m_fReloadFirstShellFraction;
	float m_fReloadRepeatFraction;
	float m_fReloadCockingFraction;
	float m_fReloadLoopTarget;
	float m_fAnimDuration;
	float m_fReloadTechniqueFactor;
	unsigned int m_nReloadAnimID;

	union 
	{
		unsigned char unionInt;

		struct 
		{
			bool m_bReloading : 1;
			bool m_bReloadQueued : 1;
			bool m_bAborted : 1;
			bool m_bCanStartToReload : 1;
		};
	};

	ZHM5ReloadController() = default;
	ZHM5ReloadController(const TEntityRef<ZHitman5>& pHitman);
	~ZHM5ReloadController() = default;
	bool QueueReload();
	void Initialize(const TEntityRef<IMorphemeEntity>& rMorphemeEntity, ZHitmanMorphemePostProcessor* pPostProcessor);
	void UpdateReload(const SHM5ControllerUpdateEvent& HM5ControllerUpdateEvent);
	bool IsReloading() const;
	bool GetCanStartToReload() const;
	float GetReloadFraction() const;
	float GetReloadWeight() const;
	void SetReloadTechniqueFactor(float fVal);
	void CutSequenceStarted();
	void SetHitmanReloading(bool bVal);
	bool CanHitmanReload();
	void StartReloadWeapons(const ZHM5WeaponSet& weaponSet);
	TEntityRef<ZHitman5> Hitman();
	void UpdateCanWeaponsBeReloaded(const ZHM5WeaponSet& weaponSet);
	bool UpdateReloadInput();
	void UpdateReloadAnim(float fDeltaGameTime);
	void EndReloadWeapon();
};
