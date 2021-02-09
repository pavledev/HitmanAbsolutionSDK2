#pragma once

#include "ZHM5BaseMovement.h"
#include "IHM5Door.h"
#include "ECPDoorMoveType.h"
#include "HM5Utils.h"
#include "ZMapPoly.h"

class ZHM5MovementOperateCPDoor : public ZHM5BaseMovement
{
public:
    TEntityRef<IHM5Door> m_pDoor;
    __int8 m_bInterrupted : 1;
    __int8 m_bStealthSituationTriggered : 1;
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
};
