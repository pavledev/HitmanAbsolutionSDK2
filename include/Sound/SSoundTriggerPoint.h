#pragma once

#include "SVector3.h"
#include "TResourcePtr.h"

class ZWaveBankData;

struct SSoundTriggerPoint
{
	SVector3 m_vPosition;
	int m_nChannel;
	int m_nChannelFlags;
	float m_fAttenuation;
	float m_fPitch;
	float m_fLowpassCutoff;
	float m_fDelayTime;
	TResourcePtr<ZWaveBankData> m_pWavebank;

	SSoundTriggerPoint(const SSoundTriggerPoint& __that);
	SSoundTriggerPoint() = default;
	~SSoundTriggerPoint() = default;
	SSoundTriggerPoint& operator=(const SSoundTriggerPoint& __that);
};
