#pragma once

#include "ZSharedPointerTarget.h"
#include "TSharedPointer.h"

class ZResourceDataBuffer : public ZSharedPointerTarget
{
public:
	unsigned char* m_pData;
	unsigned int m_nSize;
	unsigned int m_nCapacity;
	bool m_bOwnsDataPtr;

	~ZResourceDataBuffer() override = default;

	ZResourceDataBuffer() = default;
	void Insert(unsigned char* pData, unsigned int size);
	void Clear();
	unsigned char* GetData() const;
	static TSharedPointer<ZResourceDataBuffer> Create(void* data, unsigned int capacity);
	static TSharedPointer<ZResourceDataBuffer> CreateFromBorrowedData(void* buffer, unsigned int capacity);
	static TSharedPointer<ZResourceDataBuffer> Wrap(void* data, unsigned int size);
	ZResourceDataBuffer(void* buffer, unsigned int capacity, unsigned int size, bool bOwnDataPtr);
};
