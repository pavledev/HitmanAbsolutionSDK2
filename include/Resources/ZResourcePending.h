#pragma once

#include "ZResourcePtr.h"
#include "TSharedPointer.h"

class ZResourceReader;

class ZResourcePending
{
public:
	ZResourcePtr m_pResource;
	TSharedPointer<ZResourceReader> m_pResourceReader;
	int m_nPriority;
	int m_ResourceHandle;
	int m_nDataStartPosition;

	ZResourcePending() = default;
	ZResourcePending(const ZResourcePending& __that);
	ZResourcePending(const ZResourcePtr pResource, TSharedPointer<ZResourceReader> pResourceReader, int nPriority);
	~ZResourcePending() = default;
	ZResourcePending& operator=(const ZResourcePending& __that);
};
