#pragma once

#include "TResourcePtr.h"

class ZRuntimeResourceID;
class ZTextListData;

struct SSubtitleRef
{
	TResourcePtr<ZTextListData> m_TextlistResource;
	unsigned int m_nHashedLoganID;

	SSubtitleRef(ZRuntimeResourceID textlistResourceID, unsigned int nLoganID);
	SSubtitleRef(const SSubtitleRef& rhs);
	SSubtitleRef() = default;
	~SSubtitleRef() = default;
	void OnResourceChanged(const ZRuntimeResourceID& id);
	SSubtitleRef& operator=(const SSubtitleRef& __that);
};
