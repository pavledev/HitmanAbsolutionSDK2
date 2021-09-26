#pragma once

class ZCrowdGridPoint
{
public:
	short m_nHeightOffset;
	unsigned char m_nOnNavGrid;

	static void RegisterType();
	ZCrowdGridPoint() = default;
	~ZCrowdGridPoint() = default;
};
