#pragma once

#include "TRedBlackTree.h"

class IContainerType;
struct STemplatedTypeName1;

template <class T>
class TSet : public TRedBlackTree<T>
{
public:
	static STemplatedTypeName1 s_typeName;
	static IContainerType s_typeInfo;

	TSet() = default;
	~TSet() = default;
};
