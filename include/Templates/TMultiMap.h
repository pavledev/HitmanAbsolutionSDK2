#pragma once

#include "TRedBlackTree.h"
#include "TPair.h"

template<class A, class B>
class TMultiMap
{
public:
    TRedBlackTree<TPair<A const, B>> m_container;
};
