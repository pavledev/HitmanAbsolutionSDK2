#pragma once

#include "ZGameTime.h"

class SChildNetworkInfo
{
public:
    ZGameTime m_detachTime;
    unsigned int m_nNodeId;
    int m_nNetworkInstanceId;

    class SCompareNode
    {
    public:
        unsigned int m_nNodeId;

        SCompareNode(unsigned int);
        bool operator()(const SChildNetworkInfo* element);
    };

    SChildNetworkInfo();
    SChildNetworkInfo(SChildNetworkInfo const&);
    SChildNetworkInfo* operator=(SChildNetworkInfo const&);
};
