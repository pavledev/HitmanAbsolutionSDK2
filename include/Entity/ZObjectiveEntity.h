#pragma once

#include "ZEntityImpl.h"
#include "TResourcePtr.h"
#include "ZTextListData.h"

enum EObjectiveType : __int32
{
    OBJECTIVE_PRIMARY = 0x0,
    OBJECTIVE_SECONDARY = 0x1,
    OBJECTIVE_TERTIARY = 0x2
};

class ZObjectiveEntity : public ZEntityImpl
{
public:
    ZString m_sObjectiveString;
    ZString m_sDescriptionString;
    ZString m_sCompletedString;
    bool m_bActive;
    bool m_bCompleted;
    EObjectiveType m_objectiveType;
    ZString m_ObjectiveStringID;
    ZString m_DescriptionStringID;
    ZString m_CompletedStringID;
    TResourcePtr<ZTextListData> m_pTextListResource;
    TResourcePtr<ZTextListData> m_pCompletedTextListResource;
    int m_nTally;
    int m_nTallyRequired;
    ZRuntimeResourceID m_sIconResourceID;
    bool m_bShowInHUD;
    bool m_bRegisterInNotebook;
    bool m_bIsCompletable;
    ZString m_sCustomSaveTitle;
};
