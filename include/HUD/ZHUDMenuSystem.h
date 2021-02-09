#pragma once

#include "ZMenuSystem.h"
#include "EMenuId.h"
#include "ZPCOptionsHelper.h"
#include "TSet.h"
#include "STokenID.h"

class ZHUDMenuSystem : public ZMenuSystem
{
public:
    EMenuId m_eCurrentMenuId;
    int m_nPreviousDifficulty;
    bool m_bEditedContractTitle;
    bool m_bEditedContractDescription;
    ZString m_sContractCompetitionFriends;
    int m_iContractCompetitionAllow;
    int m_iContractCompetitionDuration;
    ZPCOptionsHelper m_PCOptionsHelper;
    bool m_bChangesDialogActive;
    bool m_bPCRetail;
    bool m_bButtonMappingSubmenu;
    ZMenuSpinnerItem* m_pWeaponSelectionSpinner;
    TSet<STokenID> m_aInitialItems;

    virtual void OnPCEvent(IScaleformExternalInterfaceArguments*);
    virtual ZPCOptionsHelper* GetPCOptionsHelper();
};
