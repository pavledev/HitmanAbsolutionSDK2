#pragma once
#include "d3d11.h"

#pragma warning(disable : 4005)

struct SConstBufferImpl
{
	ID3D11Buffer* m_pBuffer;
	unsigned int m_nSize;
	SConstBufferImpl* pNext;
	unsigned short m_nInternalSize;
	unsigned short _nPad;

	SConstBufferImpl() = default;
	~SConstBufferImpl() = default;
	char* Backbuffer() const;
	void UpdateSubresource() const;
};
