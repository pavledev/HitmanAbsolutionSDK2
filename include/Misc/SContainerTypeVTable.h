#pragma once

#include "ZVariantRef.h"

struct SContainerTypeVTable
{
	void* (*begin)(void* param1);
	void* (*end)(void* param1);
	void* (*next)(void* param1, void* param2);
	unsigned int (*getSize)(void* param1);
	void (*setDeserializedElement)(void* param1, ZVariantRef variantRef, int param3);
	void (*clear)(void* param1);

	SContainerTypeVTable() = default;
	~SContainerTypeVTable() = default;
};
