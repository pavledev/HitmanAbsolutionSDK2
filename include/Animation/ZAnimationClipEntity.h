#pragma once

#include "ZAnimationClipBaseEntity.h"
#include "TResourcePtr.h"
#include "EGait.h"
#include "ESpeed.h"
#include "EAnimBlendMode.h"
#include "ESyncEvent.h"
#include "MR.h"
#include "SComponentMapEntry.h"
#include "ZString.h"
#include "ZVariantRef.h"

class ZAnimationResource;
class ZComponentCreateInfo;
class ZSPUAnimationClip;
struct STypeID;

class ZAnimationClipEntity : public ZAnimationClipBaseEntity
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	float m_fDuration;
	float m_fSampleFrequency;
	float m_fLinearVelocity;
	float m_fAngularVelocity;
	unsigned short m_clipIndex;
	ZString m_sAnimName;
	TResourcePtr<ZAnimationResource> m_pAnimationResource;
	EGait m_gait;
	ESpeed m_speed;
	EAnimBlendMode m_eAnimBlendMode;
	bool m_bIsEnabled;
	unsigned char m_nOverrideStageFlags;
	bool m_bStartFromBeginning;
	bool m_bMirrored;

	static SComponentMapEntry s_componentMap[0];

	~ZAnimationClipEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	virtual void OnAnimationResourceChanged();

	ZAnimationClipEntity() = default;
	static void RegisterType();
	ZAnimationClipEntity(ZComponentCreateInfo& info);
	bool isReady() const;
	float getDuration() const;
	float getSampleFrequency() const;
	const MR::Rig* getRig() const;
	ESyncEvent getFirstSyncEvent() const;
	const MR::IAnimSource* getAnimSource() const;
	bool IsClipEnabled() const;
	void assignClipIndex(unsigned short clipIndex);
	unsigned short getClipIndex() const;
	bool compileSPUAnimationClip(ZSPUAnimationClip* spuClip, unsigned short clipIndex) const;
	EAnimBlendMode GetBlendMode() const;
	int sampleEvents(float fStartFraction, float fDeltaFraction, MR::TriggeredEventsPool* pEventsPool, MR::TriggeredEventsBuffer* pEventsBuffer) const;
	int sampleEventsInternal(float fStartFraction, float fDeltaFraction, MR::TriggeredEventsBuffer* pEventsBuffer, bool bCountOnly) const;
};
