#pragma once

#include "ZEntityImpl.h"
#include "EActionType.h"
#include "TEntityRef.h"
#include "ZBoxVolumeEntity.h"
#include "TResourcePtr.h"
#include "ZTextListData.h"
#include "ZIllegalActionEntity.h"
#include "ZHM5BaseMovement.h"
#include "IHM5Item.h"

class ZHM5Action : ZEntityImpl
{
public:
    EActionType m_eActionType;
    ZEntityRef m_Object;
    TEntityRef<ZBoxVolumeEntity> m_rActivateBoxVolume;
    ZString m_sActionName;
    bool m_bVisible;
    ZEntityRef m_Listener;
    ZString m_sDefaultItemName;
    TResourcePtr<ZTextListData> m_pTextListResource;
    ZString m_sExitTextID;
    ZString m_sCachedString;
    ZString m_sCachedExitString;
    TEntityRef<ZSpatialEntity> m_3dPromptPosition;
    TEntityRef<ZIllegalActionEntity> m_rIllegalActionEntity;
    TEntityRef<IHM5Item> m_rUserDataItem;
    ZHM5BaseMovement* m_pActionMovement;
    float4 m_vObjectCenter;
    float4 m_vObjectSize;
    bool m_bObjectDirty;
    bool m_bCallbackRegistered;
    ZEntityRef m_OwnListener;
    ZEntityRef m_rVentShaftInstance;
    float m_fButtonHeightOffset;
};