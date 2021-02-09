#pragma once

#include "ZGameTime.h"

class alignas(8) ZActionMapTree
{
public:
    ZActionMapTree* m_pkParent;
    ZActionMapTree* m_pkFirstChild;
    ZActionMapTree* m_pkNext;
    unsigned __int8 m_eType;
    unsigned __int8 m_eMods;
    __int16 m_iLastDevice;
    __int16 m_iDeviceId;
    __int16 m_iControlId;
    __int16 m_iOrgDeviceId;
    __int16 m_iOrgControlId;
    char m_acName[64];
    float m_fConstant;
    ZGameTime m_tLastFired;
    ZActionMapTree* m_pkGetTree;

    virtual ~ZActionMapTree();
};
