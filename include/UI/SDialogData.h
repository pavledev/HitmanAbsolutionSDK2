#pragma once

#include "EUIDialog.h"
#include "EDialogOptions.h"
#include "EUIText.h"
#include "ZString.h"
#include "EDialogIcon.h"
#include "ZEvent.h"
#include "EDialogContext.h"
#include "EDialogResult.h"
#include "ZEventNull.h"

class SDialogData
{
public:
    EUIDialog m_eDialog;
    EDialogOptions m_eDialogOptions;
    EUIText m_eTitle;
    EUIText m_eMessage;
    ZString m_sMessage;
    EUIText m_eConfirmButton;
    EUIText m_eAlternativeButton;
    EUIText m_eDenyButton;
    EDialogIcon m_eIcon;
    ZEvent<EDialogContext, EUIDialog, EDialogResult, ZEventNull, ZEventNull> m_Callback;
    unsigned int m_nDuration;
    ZString m_sOverrideMessage;
};
