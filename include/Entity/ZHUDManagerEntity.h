#pragma once

#include "ZEntityImpl.h"
#include "TEntityRef.h"
#include "ZRuntimeResourceID.h"
#include "ZResourcePtr.h"
#include "IScaleformPlayer.h"

class ZHUDManagerEntity : public ZEntityImpl
{
public:
    TEntityRef<IScaleformPlayer> m_mcHUD;
    ZRuntimeResourceID m_NotebookLibID;
    ZRuntimeResourceID m_ContractLibID;
    float m_ObjectiveTimeMin;
    float m_ObjectiveTimeMax;
    float m_ObjectiveTimeFactor;
    ZResourcePtr m_pDisguiseOSDResource;
};
