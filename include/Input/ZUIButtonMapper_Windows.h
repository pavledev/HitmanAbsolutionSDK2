#pragma once

#include "ZString.h"
#include "ResetStatus.h"
#include "ZDelegate.h"
#include "EDialogContext.h"
#include "EUIDialog.h"
#include "EDialogResult.h"

class alignas(8) ZUIButtonMapper_Windows
{
public:
    ZString m_ButtonMappingName;
    ZString m_ButtonMappingResult;
    int m_iButtonMappingIndex;
    int m_iButtonMappingDevice;
    int m_iButtonMappingDikCode;
    ResetStatus m_iResetStatus;
    ZDelegate<void __cdecl(EDialogContext, EUIDialog, EDialogResult)> m_dialogCallback;
};
