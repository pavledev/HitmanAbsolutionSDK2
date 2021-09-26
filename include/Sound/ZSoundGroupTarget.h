#pragma once

#include "ZGameTime.h"
#include "ZString.h"

class ZSoundGroupInternal;
struct float4;

class __declspec(novtable) ZSoundGroupTarget
{
public:
	ZSoundGroupInternal* m_pSoundGroupInternal;
	bool m_bMutedBySoundGroup;
	float m_fSoundGroupFadeLevel;
	float m_fSoundGroupFadeDelta;

	virtual ~ZSoundGroupTarget() = default;
	virtual int GetPriority() = 0;
	virtual float GetAudibility(bool param1) = 0;
	virtual float GetSquaredDistanceToListener(const float4& param1) = 0;
	virtual ZGameTime GetTimestamp() = 0;
	virtual void StopTarget() = 0;
	virtual ZString GetSoundGroupTargetName() const = 0;
	virtual bool UpdateSoundGroupFade(bool bMuted, float fFadeTime, float fDeltaTime);

	ZSoundGroupTarget() = default;
	void SetInitialSoundGroupFadeState(bool bMuted, float fFadeLevel, float fFadeDelta);
	void AddToSoundGroup(ZSoundGroupInternal* pInternal);
	void RemoveFromSoundGroup();
};
