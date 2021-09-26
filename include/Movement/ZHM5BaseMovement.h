#pragma once

#include "EBaseMovementType.h"
#include "TEntityRef.h"
#include "EHM5GameInputFlag.h"
#include "EHM5ResetReason.h"

class ZHitman5;
class IMorphemeEntity;
class ZMorphemeNetworkInstance;
struct SBaseMovmentCollisionInfo;
struct SCameraUpdateEvent;
struct SGameUpdateEvent;
struct SHM5AimInfo;
struct SHM5GameCamParams;
struct SHM5LookAtInfo;
struct SInputRestriction;
struct SMatrix;
struct float4;

class ZHM5BaseMovement
{
public:
	enum eMoveDir
	{
		eMoveIdle = 0,
		eMoveLeft = 1,
		eMoveRight = 2,
		eMoveUp = 3,
		eMoveDown = 4,
		eMoveLeft45Up = 5,
		eMoveRight45Up = 6,
		eMoveLeft45Down = 7,
		eMoveRight45Down = 8
	};

	enum eContextFlags
	{
		CF_PLAYERCOLLISION = 1,
		CF_ACTIONCLIENT = 2,
		CF_INVENTORYSELECT = 4,
		CF_ITEMEQUIPPED = 8,
		CF_DUALWIELDING = 16,
		CF_GRAVITY = 32,
		CF_POSTPROCESSOR = 64,
		CF_TURNONSPOT = 128,
		CF_ANCHORCOLLISION = 256,
		CF_NORMALIZE_MAT = 512,
		CF_PLAYERNPCCOLLISION = 1024,
		CF_FPSDRAWMODE = 2048,
		CF_CORRECTSURFACESPEED = 4096
	};

	unsigned int m_nRootNodeID;
	bool m_bActive;
	bool m_bCanActivate;
	IMorphemeEntity* m_pMorphemeEntity;
	ZMorphemeNetworkInstance* m_pMorphemeNetwork;
	unsigned int m_nContextFlags;
	unsigned int m_nPostProcessorComponents;
	EBaseMovementType m_eType;
	TEntityRef<ZHitman5> m_pHitman;
	EHM5GameInputFlag m_eMarkInputFlagAsConsumed;

	virtual ~ZHM5BaseMovement() = default;
	virtual unsigned int GetRootNodeID() const;
	virtual void CollectPreUpdateInfo(const ZHM5BaseMovement* pCurrentMovement);
	virtual bool WantControl() const;
	virtual void GotControl(ZHM5BaseMovement* pPrevMovement, bool bForced);
	virtual void ActivateMovement();
	virtual void DeactivateMovement();
	virtual void UpdateMovementMatPos(SMatrix& mvFrom, SMatrix& mvTo, const SGameUpdateEvent& updateEvent);
	virtual void UpdatePostCam(SMatrix& mvFrom, SMatrix& mvTo);
	virtual void UpdateColiCheckedGroundMovement(const SMatrix& mvFrom, const SMatrix& mvTo, const SBaseMovmentCollisionInfo& CollisionInfo);
	virtual void UpdateOutsideControl();
	virtual bool AllowRemoveControl(const ZHM5BaseMovement* pWantControlMovement) const;
	virtual void RemoveControl();
	virtual float GetWildCardTransitionTime(EBaseMovementType ePrevMoveType) const;
	virtual bool CanActivate() const;
	virtual void ResetMovement(EHM5ResetReason eReason);
	virtual void GetInputRestriction(SInputRestriction& InputRestriction) const;
	virtual bool OverridePlayerCollisionPosition(float4& vPos) const;
	virtual void UpdateCameraProfile(SHM5GameCamParams& CurrentProfile);
	virtual void UpdateCameraEvent(SCameraUpdateEvent& CameraUpdateEvent) const;
	virtual unsigned int ShowItems() const;
	virtual void ReinitializeMorphemeData(IMorphemeEntity* pMorphemeEntity);
	virtual void HitmanOutfitMeshChanged();
	virtual void UpdateAim(SHM5AimInfo& sAimInfo) const;
	virtual void UpdateLookAt(SHM5LookAtInfo& sAimInfo) const;
	virtual void PrepareForCutSequence();
	virtual void UpdateMovement();
	virtual void UpdateGroundMovement(SMatrix& mvFrom, SMatrix& mvTo);

	ZHM5BaseMovement() = default;
	ZHM5BaseMovement(IMorphemeEntity* pMorphemeEntity, const TEntityRef<ZHitman5>& pHitman, EBaseMovementType eType);
	EBaseMovementType GetType() const;
	unsigned int GetContextFlags() const;
	unsigned int GetPostProcessorComponents() const;
	bool IsActive();
	bool IsAgilityMovement();
	void CalcColiFreeExitMatPos(SMatrix& mvExitMatPos) const;
	TEntityRef<ZHitman5> Hitman() const;
	void MarkInputFlagAsConsumed(EHM5GameInputFlag flag);
	void ResetConsumedInputFlag();
	void ProcessMarkedInputFlag();
	void SetContextFlags(const unsigned int nFlags);
	void ClearContextFlags(const unsigned int nFlags);
	bool ControllerInputActive() const;
};
