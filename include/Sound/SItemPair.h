#pragma once

#include "TEntityRef.h"
#include "ZSoundBlendItem.h"

struct SItemPair
{
	TEntityRef<ZSoundBlendItem> m_Item[2];

	SItemPair(const SItemPair& other);
	SItemPair() = default;
	bool Contains(TEntityRef<ZSoundBlendItem> item) const;
	bool IsEmpty() const;
	~SItemPair() = default;
	SItemPair& operator=(const SItemPair& __that);
};
