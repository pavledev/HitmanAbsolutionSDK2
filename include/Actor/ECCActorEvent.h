#pragma once

enum ECCActorEvent
{
	eCCActorEvent_NeckSnap = 0,
	eCCActorEvent_StrangleStart = 1,
	eCCActorEvent_StrangleEnd = 2,
	eCCActorEvent_PropAttack = 3,
	eCCActorEvent_Impact = 4,
	eCCActorEvent_ImpactFinal = 5,
	eCCActorEvent_FiberwireKill = 6,
	eCCActorEvent_FiberwireInit = 7,
	eCCActorEvent_ExecutePistol = 8,
	eCCActorEvent_StrangleMoveInit = 9,
	eCCActorEvent_AttackChainCivilian = 10,
	eCCActorEvent_PropAttackInit = 11,
	eCCActorEvent_HumanShieldGrab = 12,
	eCCActorEvent_HumanShieldKill = 13,
	eCCActorEvent_Grab = 14,
	eCCActorEvent_Fall = 15,
	eCCActorEvent_ImpactHitman = 16
};
