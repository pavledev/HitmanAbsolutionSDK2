#pragma once

enum EAIEventType
{
	AIET_None = 0,
	AIET_Ignore = 1,
	AIET_ShootTarget = 2,
	AIET_Order_Target = 3,
	AIET_END_BOOLEAN_EVENTS = 4,
	AIET_LookedAt = 5,
	AIET_Goal_Kill = 6,
	AIET_Goal_Arrest = 7,
	AIET_Goal_HelpCivilian = 8,
	AIET_Goal_Investigate = 9,
	AIET_Goal_InvestigateDisguise = 10,
	AIET_Goal_InvestigateDeadBody = 11,
	AIET_Goal_HandleTrespasser = 12,
	AIET_Goal_InvestigateCautious = 13,
	AIET_Goal_InvestigateCurious = 14,
	AIET_Goal_InvestigateStanding = 15,
	AIET_Goal_HandleFusebox = 16,
	AIET_Goal_AvoidExplosion = 17,
	AIET_Goal_Hunt = 18,
	AIET_Goal_Evacuate = 19,
	AIET_Killer = 20,
	AIET_Hunting = 21,
	AIET_Suspicious = 22,
	AIET_DisguiseSuspicious = 23,
	AIET_DamagingMe = 24,
	AIET_KnownInCloset = 25,
	AIET_KnownInVent = 26,
	AIET_NearSabotagedFusebox = 27,
	AIET_FuseboxSabotaged = 28,
	AIET_FuseboxAck = 29,
	AIET_DisablingFusebox = 30,
	AIET_SoundFootsteps = 31,
	AIET_SoundThrownItemCollision = 32,
	AIET_SoundGunSilenced = 33,
	AIET_SoundHitmanGunSilenced = 34,
	AIET_SoundEmptyGun = 35,
	AIET_SoundCCBreakNeck = 36,
	AIET_SoundCCChoke = 37,
	AIET_SoundCCFiberwire = 38,
	AIET_SoundBulletImpact = 39,
	AIET_SoundSpeakBark = 40,
	AIET_SoundRadio = 41,
	AIET_SoundAlarm = 42,
	AIET_SoundSpeakPainBehind = 43,
	AIET_SoundCloseCombat = 44,
	AIET_SoundSpeakPain = 45,
	AIET_SoundSpeakScream = 46,
	AIET_SoundGunShot = 47,
	AIET_SoundHitmanGunShot = 48,
	AIET_SoundExplosion = 49,
	AIET_SoundAccident = 50,
	AIET_InSight = 51,
	AIET_FullAttention = 52,
	AIET_ReactedTo = 53,
	AIET_ReactTarget = 54,
	AIET_StanddownHolster = 55,
	AIET_ForcedIllegal = 56,
	AIET_HitByItem = 57,
	AIET_Trespassing_Strike_1 = 58,
	AIET_Trespassing_Strike_2 = 59,
	AIET_Investigate_Strike_1 = 60,
	AIET_Investigate_Strike_2 = 61,
	AIET_Weird_Strike_1 = 62,
	AIET_Weird_Strike_2 = 63,
	AIET_StandingTooClose = 64,
	AIET_IgnoreDeadBodies = 65,
	AIET_END_NORMAL_EVENTS = 66
};
