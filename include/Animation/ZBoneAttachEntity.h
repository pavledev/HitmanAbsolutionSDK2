#pragma once

#include "ZEntityImpl.h"
#include "TEntityRef.h"
#include "ZLinkedEntity.h"

class ZBoneAttachEntity : ZEntityImpl
{
public:
    TEntityRef<ZLinkedEntity> m_linkedEntity;
    ZString m_BoneName;
    TEntityRef<ZSpatialEntity> m_spatial;
    bool m_bStartAttached;

    enum EResetMode : __int32
    {
        eAtBoneOrigin = 0x0,
        eKeepOffset = 0x1,
    } m_eResetMode;

    bool m_bIsAttached;
    unsigned int m_nGlobalBoneID;
    bool m_bGameStarted;
    TEntityRef<ZLinkedEntity> m_AttachLinkedEntity;
    TEntityRef<ZSpatialEntity> m_AttachSpatial;
};
