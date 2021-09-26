#pragma once

#include "TEntityRef.h"

class ZHM5MovementShootingBallet;
class ZHM5SBTagMode;
class ZHM5SBAnimDatabase;
class ZHM5SBCinematicExecution;
class ZHitman5;
class IMorphemeEntity;
class ZHM5SBCameraProfileDatabase;
class ZPathfinder2;

struct SHM5SBShared
{
	TEntityRef<ZHitman5> m_pHitman;
	ZHM5MovementShootingBallet* m_pMovementShootingBallet;
	ZHM5SBTagMode* m_pTagMode;
	ZHM5SBAnimDatabase* m_pAnimDatabase;
	ZHM5SBCinematicExecution* m_pCinematicExecution;
	ZPathfinder2* m_pPathfinder;
	IMorphemeEntity* m_pMorpheme;
	ZHM5SBCameraProfileDatabase* m_pSBCameraProfileDatabase;
	bool m_bHolsterOnCancel;

	SHM5SBShared() = default;
	~SHM5SBShared() = default;
};
