#pragma once

#include "ZEntityImpl.h"
#include "EWhenToShowDiscoverMessage.h"
#include "TResourcePtr.h"
#include "ZTextListData.h"
#include "TEntityRef.h"
#include "ZRuntimeResourceIDEntity.h"
#include "ZMetaContentAccessEntity.h"
#include "ZGlobalItemKit.h"
#include "ZTokenIDEntity.h"
#include "ZDynamicResourceLibrary.h"

class ZDLCDescriptor : public ZEntityImpl
{
public:
    ZString m_sTitleID;
    ZString m_sDiscoveredDescriptionID;
    EWhenToShowDiscoverMessage m_eShowDiscoverMessage;
    TResourcePtr<ZTextListData> m_pTextListResource;
    TArray<TEntityRef<ZRuntimeResourceIDEntity> > m_MenuEntities2;
    TArray<TEntityRef<ZMetaContentAccessEntity> > m_MetaContent;
    TArray<TEntityRef<ZGlobalItemKit> > m_GlobalKits;
    TEntityRef<ZTokenIDEntity> m_TokenID;
    TArray<ZDynamicResourceLibrary*> m_aMenuEntityLibraries;
};
