#pragma once

struct SRoomInsideOutsideInfo
{
	unsigned short nRoomId;
	unsigned short nAreaBoxId;
	unsigned short nRoomIdInside;
	unsigned short nRoomIdOutside;
	bool bOutside;

	SRoomInsideOutsideInfo() = default;
	~SRoomInsideOutsideInfo() = default;
};
