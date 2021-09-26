#pragma once

#include "ZShadowContentKitList.h"
#include "TMap.h"

struct STokenID;

template <class A, class B, class C, class D>
class ZContentKitList
{
public:
    ZShadowContentKitList m_List;
    TMap<STokenID, D> m_PersistentState;

	ZContentKitList() = default;
	~ZContentKitList() = default;
};
