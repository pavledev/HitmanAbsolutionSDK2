#pragma once

#include "ZEntityImpl.h"
#include "EControlButtonName.h"
#include "TResourcePtr.h"
#include "ZTextListData.h"
#include "EHintMessageType.h"
#include "EHintMessageSoundType.h"
#include "EMenuId.h"

class ZHintMessageEntity : public ZEntityImpl
{
public:
    EControlButtonName m_eButtonFirst;
    EControlButtonName m_eButtonSecond;
    ZString m_sTextHeadline;
    TResourcePtr<ZTextListData> m_pHeadlineTextListResource;
    ZString m_sCachedHeadlineString;
    ZString m_sText;
    TResourcePtr<ZTextListData> m_pTextListResource;
    ZString m_sCachedString;
    ZResourcePtr m_pTutorialImage;
    int m_iPriority;
    EHintMessageType m_eHintType;
    float m_fDuration;
    bool m_bWorksInContractsMode;
    bool m_bWorksInPuristDifficulty;
    EHintMessageSoundType m_eHintSound;
    bool m_bSlowDownTime;
    bool m_bTutorialNotebookPrompt;
    EMenuId m_eNotebookPage;
};
