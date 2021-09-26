#pragma once

#include "SRenderRecordRingBufferReservation.h"

struct SRenderRecordRingBuffer
{
	unsigned char* nPut;
	unsigned char* nGet;
	SRenderRecordRingBufferReservation* pReservation;
	unsigned char* nStart;
	unsigned char* nEnd;
	unsigned char* nRealEnd;
	unsigned int nSize;
	unsigned int nBreakWhenFull;

	SRenderRecordRingBuffer() = default;
	~SRenderRecordRingBuffer() = default;
};
