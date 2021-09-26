#pragma once

#include "TEntityRef.h"

class IHM5Item;

struct sAttacherBoneElement
{
	TEntityRef<IHM5Item> rItem;
	int m_nBoneId;

	sAttacherBoneElement() = default;
	bool IsInitialized();
	void Empty();
	~sAttacherBoneElement() = default;
};
