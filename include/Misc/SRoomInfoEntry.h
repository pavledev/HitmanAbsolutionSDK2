#pragma once

struct SRoomInfoEntry
{
	unsigned short nStart;
	unsigned short nCount;

	SRoomInfoEntry(const SRoomInfoEntry& copy);
	SRoomInfoEntry() = default;
	~SRoomInfoEntry() = default;
	SRoomInfoEntry operator=(const SRoomInfoEntry& rhs);
};
