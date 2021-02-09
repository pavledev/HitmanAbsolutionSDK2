#pragma once

#include "TEntityRef.h"
#include "ZCheckPointEntity.h"

class alignas(4) SPendingCheckpointData
{
public:
    TEntityRef<ZCheckPointEntity> m_pCheckPointEntity;
    bool m_bUseSave;
    bool m_bSaveBeforeChange;
    bool m_bRestoring;
};
