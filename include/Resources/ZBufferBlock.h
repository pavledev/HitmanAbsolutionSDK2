#pragma once

class ZBufferBlock
{
public:
	unsigned char* pData;
	unsigned int nPosition;
	unsigned int nReadSize;
	volatile bool m_bLoaded;

	ZBufferBlock() = default;
	~ZBufferBlock() = default;
	void Reset();
};
