#pragma once

#include <iostream>
#include <map>
#include "ZActorManager.h"
#include "ZLevelManager.h"
#include "ZHUDManager.h"
#include "ZUserFeedbackManager.h"
#include "Globals.h"

using namespace std;

class Mods
{
private:
	static map<int, __int16> actorTextIDs;
public:
	void EnableGravityGun();
	void KillNearbyActors();
	void DisplayNearbyActorsInfo();

	const char* GetActorType(EActorType m_eActorType);
};