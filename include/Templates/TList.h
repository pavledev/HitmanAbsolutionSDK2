#pragma once

class IContainerType;
struct STemplatedTypeName1;
template <class T> class TListNode;

template <class T>
class TList
{
public:
    struct ZFakeListNode
    {
        TListNode<T>* m_pFirst;
        TListNode<T>* m_pLast;
    };

    unsigned int m_nSize;
    ZFakeListNode m_list;

    static STemplatedTypeName1 s_typeName;
    static IContainerType s_typeInfo;

    TList() = default;
    ~TList() = default;

    unsigned int Size()
    {
        return this->m_nSize;
    }
};
