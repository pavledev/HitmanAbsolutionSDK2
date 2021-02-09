#pragma once

#include "TArrayFixedHeap.h"
#include "SKnownEntity.h"
#include "TFixedArray.h"
#include "SLink.h"
#include "SHashNode.h"

class alignas(16) ZKnownEntityContainer
{
public:
    unsigned int m_nNumAllocatedKnownEntities;
    TArrayFixedHeap<SKnownEntity, 3072> m_KnownEntities;
    TFixedArray<SLink, 4096> m_hashLinks;
    TFixedArray<SLink, 600> m_actorLinks;
    TFixedArray<SHashNode, 4096> m_hashTable;
    unsigned int m_nFirstFreeHashNode;
};
