#pragma once

#include "ZEntityImpl.h"
#include "ZDynamicResourceLibrary.h"
#include "TEntityRef.h"
#include "ZScaleformResourceEntity.h"
#include "IScaleformPlayer.h"

class ZNotebookEntity : public ZEntityImpl
{
public:
    ZDynamicResourceLibrary* m_pCheckpointImageLib;
    TEntityRef<ZScaleformResourceEntity> m_pCheckpointImageEntity;
    TEntityRef<IScaleformPlayer> m_mcNotebook;
};
