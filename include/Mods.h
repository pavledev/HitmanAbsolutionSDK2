#pragma once

#include <Windows.h>
#include <iostream>
#include <map>
#include <corecrt_math_defines.h>
#include "ZActorManager.h"
#include "ZLevelManager.h"
#include "ZHUDManager.h"
#include "ZUserFeedbackManager.h"
#include "ZHM5ActionManager.h"
#include "ZHM5SBTargetPropManager.h"
#include "TTypeIDHelper.h"
#include "Singletons.h"
#include "ZEngineAppCommon.h"
#include "ZHM5ItemWeapon.h"
#include "ZHM5ProjectilePool.h"
#include "ZHM5Projectile.h"
#include "ZHitman5.h"
#include "ZHM5MainCamera.h"
#include "Globals.h"

#define VK_OEM_PLUS 0xBB
#define VK_OEM_COMMA 0xBC
#define VK_OEM_MINUS 0xBD
#define VK_OEM_PERIOD 0xBE

using namespace std;

class Mods
{
private:
	inline static std::map<int, short> actorTextIDs;
	float detectRadius = 10.0;
	float powerLevel = 10.0;
	const int increaseRadiusKey = VK_OEM_PERIOD;
	const int decreaseRadiusKey = VK_OEM_COMMA;
	const int increasePowerLevel = VK_OEM_PLUS;
	const int decreasePowerLevel = VK_OEM_MINUS;
	inline static IHM5Item* item;

	enum class Moving
	{
		no = 0,
		actor = 1,
		item = 2,
		prop = 3
	};

	void UpdateGravityGun(TEntityRef<ZSpatialEntity> spatialEntityRef, ZHitman5* player, bool firstRun);
	bool ProcessItems(TEntityRef<ZSpatialEntity>& spatialEntity, ZHitman5* player, Moving& entity, int& selected);
	bool ProcessActors(TEntityRef<ZSpatialEntity>& spatialEntity, ZHitman5* player, Moving& entity, int& selected);
	bool ProcessProps(TEntityRef<ZSpatialEntity>& spatialEntity, ZHitman5* player, Moving& entity, int& selected);
	float ATan2_0To2Pi(float y, float x);

public:
	void EnableGravityGun();
	void KillNearbyActors();
	void DisplayNearbyActorsInfo();
	void ProcessGrapplingHook();
	void Fly();
	void CreateAndEnableHooks();

	const char* GetActorType(EActorType m_eActorType);
};
