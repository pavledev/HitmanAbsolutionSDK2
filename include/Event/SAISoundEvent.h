#pragma once

#include "ZEntityRef.h"
#include "TEntityRef.h"
#include "EAIEventType.h"
#include "float4.h"

class ZSpatialEntity;

struct SAISoundEvent
{
	ZEntityRef m_pSender;
	TEntityRef<ZSpatialEntity> m_pSpatial;
	float4 m_vPosition;
	unsigned short m_nRoomID;
	EAIEventType m_eType;
	float m_fRange;

	SAISoundEvent(const SAISoundEvent& __that);
	SAISoundEvent() = default;
	~SAISoundEvent() = default;
	SAISoundEvent& operator=(const SAISoundEvent& __that);
};
