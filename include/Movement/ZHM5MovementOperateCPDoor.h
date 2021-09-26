#pragma once

#include "ZHM5BaseMovement.h"
#include "IHM5Door.h"
#include "HM5Utils.h"
#include "ZMapPoly.h"

class ZHM5MovementOperateCPDoor : public ZHM5BaseMovement
{
public:
	enum ECPDoorMoveType
	{
		eCPDoorMoveType_Enter = 0,
		eCPDoorMoveType_Loop = 1,
		eCPDoorMoveType_Exit = 2
	};

	TEntityRef<IHM5Door> m_pDoor;
	bool m_bInterrupted : 1;
	bool m_bStealthSituationTriggered : 1;
	float m_fPickLockTimeElapsed;
	float m_fAlignTimeLimit;
	float m_fAlignTime;
	float m_fHidePadLockFraction;
	float m_fPrevAnimFraction;
	ECPDoorMoveType m_eMoveType;
	unsigned int m_nActiveAnimID;
	HM5Utils::SAnimBlend m_sAnimBlend;
	SMatrix m_mvStartMatPos;
	SMatrix m_mvDestMatPos;
	SMatrix m_mvExitMatPos;
	ZMapPoly m_MapPoly;

	~ZHM5MovementOperateCPDoor() override = default;
	bool WantControl() const override;
	void GotControl(ZHM5BaseMovement* pPrevMovement, bool bForced) override;
	void ActivateMovement() override;
	void UpdateMovementMatPos(SMatrix& mvFrom, SMatrix& mvTo, const SGameUpdateEvent& updateEvent) override;
	void RemoveControl() override;
	void ResetMovement(EHM5ResetReason eReason) override;

	ZHM5MovementOperateCPDoor() = default;
	ZHM5MovementOperateCPDoor(IMorphemeEntity* pMorphemeEntity, const TEntityRef<ZHitman5>& pHitman);
	void SetDoor(TEntityRef<IHM5Door> pDoor);
	void InterruptMovement(bool bVoluntary);
	bool HasBeenInterrupted() const;
	unsigned int GetAnimNodeID(ECPDoorMoveType eMoveType) const;
	void SetAnimNodeID();
};
