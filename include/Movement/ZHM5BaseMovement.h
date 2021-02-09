#pragma once

#include "IMorphemeEntity.h"
#include "EBaseMovementType.h"
#include "TEntityRef.h"
#include "EHM5GameInputFlag.h"
#include "SGameUpdateEvent.h"
#include "SBaseMovmentCollisionInfo.h"
#include "EHM5ResetReason.h"
#include "SInputRestriction.h"
#include "SHM5GameCamParams.h"
#include "SCameraUpdateEvent.h"
#include "SHM5AimInfo.h"
#include "SHM5LookAtInfo.h"

class ZHitman5;

class alignas(4) ZHM5BaseMovement
{
public:
    unsigned int m_nRootNodeID;
    bool m_bActive;
    bool m_bCanActivate;
    alignas(4) IMorphemeEntity* m_pMorphemeEntity;
    ZMorphemeNetworkInstance* m_pMorphemeNetwork;
    unsigned int m_nContextFlags;
    unsigned int m_nPostProcessorComponents;
    EBaseMovementType m_eType;
    TEntityRef<ZHitman5> m_pHitman;
    EHM5GameInputFlag m_eMarkInputFlagAsConsumed;

    virtual ~ZHM5BaseMovement();
    virtual unsigned int GetRootNodeID();
    virtual void CollectPreUpdateInfo(const ZHM5BaseMovement*);
    virtual bool WantControl();
    virtual void GotControl(ZHM5BaseMovement*, bool);
    virtual void ActivateMovement();
    virtual void DeactivateMovement();
    virtual void UpdateMovementMatPos(SMatrix*, SMatrix*, const SGameUpdateEvent*);
    virtual void UpdatePostCam(SMatrix*, SMatrix*);
    virtual void UpdateColiCheckedGroundMovement(const SMatrix*, const SMatrix*, const SBaseMovmentCollisionInfo*);
    virtual void UpdateOutsideControl();
    virtual bool AllowRemoveControl(const ZHM5BaseMovement*);
    virtual void RemoveControl();
    virtual float GetWildCardTransitionTime(EBaseMovementType);
    virtual bool CanActivate();
    virtual void ResetMovement(EHM5ResetReason);
    virtual void GetInputRestriction(SInputRestriction*);
    virtual bool OverridePlayerCollisionPosition(float4*);
    virtual void UpdateCameraProfile(SHM5GameCamParams*);
    virtual void UpdateCameraEvent(SCameraUpdateEvent*);
    virtual unsigned int ShowItems();
    virtual void ReinitializeMorphemeData(IMorphemeEntity*);
    virtual void HitmanOutfitMeshChanged();
    virtual void UpdateAim(SHM5AimInfo*);
    virtual void UpdateLookAt(SHM5LookAtInfo*);
    virtual void PrepareForCutSequence();
    virtual void UpdateMovement();
    virtual void UpdateGroundMovement(SMatrix*, SMatrix*);
};
