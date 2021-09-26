#pragma once

#include "TRedBlackTree.h"

class IContainerType;
struct STemplatedTypeName2;
template <class A, class B> class TPair;

template <class A, class B>
class TMultiMap
{
public:
    TRedBlackTree<TPair<A const, B>> m_container;

    static STemplatedTypeName2 s_typeName;
    static IContainerType s_typeInfo;

    TMultiMap() = default;
    ~TMultiMap() = default;
};
