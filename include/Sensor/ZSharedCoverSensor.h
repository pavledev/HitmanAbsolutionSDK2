#pragma once

#include "TMap.h"
#include "SRoomCoverInfo.h"

class ZActor;

class ZSharedCoverSensor
{
public:
	TMap<unsigned short, SRoomCoverInfo> m_RoomGroups;

	virtual ~ZSharedCoverSensor() = default;

	ZSharedCoverSensor() = default;
	void Reset();
	void Update(const TArrayRef<TEntityRef<ZActor>>& actors);
	void AppendCoversForRoom(unsigned short nRoomID, TArray<ZHM5CoverPlane*>& Covers);
	bool CheckLOF(const float4& vFrom, const float4& vTo);
};
