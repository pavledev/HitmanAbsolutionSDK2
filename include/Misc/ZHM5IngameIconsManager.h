#pragma once

#include "TFixedArray.h"
#include "SIconElement.h"

class ZUserFeedbackManager;

class ZHM5IngameIconsManager
{
public:
    TFixedArray<SIconElement, 10> m_IconElements;
    const ZUserFeedbackManager* m_rUserFBManager;
};
