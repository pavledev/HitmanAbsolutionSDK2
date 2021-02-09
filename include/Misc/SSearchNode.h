#pragma once

struct SSearchNode
{
public:
    unsigned int m_nNodeKey;
    unsigned __int16 m_nPolygonID;
    unsigned __int16 m_nPriorityNodeID;
    float m_fHeuristicCost;
    float m_fAccumulatedCost;
    const SSearchNode* m_pCameFrom;
};
