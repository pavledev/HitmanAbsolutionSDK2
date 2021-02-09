#pragma once

#include "SAnimNodeHitman.h"
#include "SAnimNodeNPC.h"
#include "TEntityRef.h"
#include "ZHitman5.h"

class alignas(8) ZHM5CCAnimDatabase
{
    SAnimNodeHitman m_aHitmanAnimNodes[165];
    unsigned int m_nHitmanNumNodes;
    unsigned int m_nHitmanNumNodesNoChildNetworks;
    unsigned int m_nHitmanCCNode;
    unsigned int m_nHitmanRootNode[2];
    unsigned int m_nHitmanBossRootNode[2];
    unsigned int m_anHitmanNodeCount[45][9];
    unsigned int m_nCCIdleRequest;
    SAnimNodeHitman* m_apSortedAnimList[165];
    unsigned int m_nSortedListSize;
    SAnimNodeNPC m_aNPCAnimNodes[165];
    unsigned int m_anNPCNodeCount[45][9];
    unsigned int m_nNPCNumNodes;
    unsigned int m_nNPCNumNodesNoChildNetworks;
    unsigned int m_anNPCRootNodes[2];
    unsigned int m_nNPCCCNode;
    unsigned int m_nNPCBlendNode;
    unsigned int m_anNPCPassiveIdleNodes[2];
    unsigned int m_anNPCPacifyIdleNodes[2];
    unsigned int m_anNPCFightIdleNodes[2];
    bool m_bNPCNodesFound;
    bool m_bHitmanNodesFound;
    bool m_bNPCChildNodesFound;
    bool m_bHitmanChildNodesFound;
    TEntityRef<ZHitman5> m_pHitman;

    class GetSubtypeName
    {
    public:
        class __l2
        {
        public:
            class SSubtypeName
            {
            public:
                const ZString m_sName;
                ECCNodeSubtype m_eNodeSubtype;
            };
        };
    };

    class GetName
    {
    public:
        class __l2
        {
        public:
            class SNodeName
            {
            public:
                const ZString m_sName;
                ECCNodeType m_eNodeType;
            };
        };
    };
};
