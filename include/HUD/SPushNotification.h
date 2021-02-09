#pragma once

#include "TMap.h"
#include "ZString.h"
#include "ZVariant.h"
#include "EPushNotificationType.h"
#include "EMenuId.h"

class SPushNotification
{
public:
    bool bShown;
    TMap<ZString, ZVariant> info;
    float fDisplayTime;
    EPushNotificationType ePushNotificationType;
    EMenuId eMenuID;
    int nItemID;
};
