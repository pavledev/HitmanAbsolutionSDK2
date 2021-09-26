#pragma once

#include "SQV.h"
#include "SVector3.h"
#include "ZGateEntity.h"
#include "SRoomInfoEntry.h"

struct SGateInfoHeader
{
	SQV mTransform;
	SVector3 m_vSize;
	ZGateEntity* pGateEntity;
	SRoomInfoEntry Clients;
	float fClipDistance;
	unsigned short nCurrentRoom;
	unsigned short nNeighbourRoom;
	unsigned short nFlags : 15;
	bool m_bIsOpen : 1;

	SGateInfoHeader(const SGateInfoHeader& __that);
	SGateInfoHeader() = default;
	~SGateInfoHeader() = default;
	float4 GetNormal() const;
	void GetPortalWS(float4& topLeft, float4& topRight, float4& bottomLeft, float4& bottomRight) const;
	SGateInfoHeader& operator=(const SGateInfoHeader& __that);
};
