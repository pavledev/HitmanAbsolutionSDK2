#pragma once

#include "ZEntityImpl.h"
#include "TEntityRef.h"
#include "ZTokenIDEntity.h"
#include "TResourcePtr.h"
#include "ZTextListData.h"
#include "EShowContent.h"

class ZContentKitEntity : public ZEntityImpl
{
public:
    TEntityRef<ZTokenIDEntity> m_Token;
    ZString m_TitleLoganID;
    ZString m_DescriptionLoganID;
    TResourcePtr<ZTextListData> m_pTextListResource;
    ZString m_sCachedTitle;
    ZString m_sCachedDescription;
    EShowContent m_eShowInNotebook;
    EShowContent m_eShowOnCampaignEndScreen;
    EShowContent m_eShowOnContractsEndScreen;
    EShowContent m_eShowInSafeHouse;
    EShowContent m_eShowInGearSelection;
    bool m_bStartsLocked;
    int m_iUnlockPrice;

    virtual bool PickedUp(int, int);
    virtual bool WasPickedUp(int, int);
    virtual bool IsNewPickUp(int, int);
};
