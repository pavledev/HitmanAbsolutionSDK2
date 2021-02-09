#pragma once

#include "ZSimpleModuleBase.h"
#include "ZConfiguration.h"
#include "ZHM5OSD.h"
#include "ZEntitySceneContext.h"
#include "ZUserFeedbackManager.h"
#include "SInfoText.h"

class alignas(4) ZHitman5Module : public ZSimpleModuleBase, public ZConfiguration
{
public:
    ZHM5OSD* m_pOSD;
    ZEntitySceneContext* m_pSceneContext;
    ZUserFeedbackManager* m_pUserFeedbackManager;
    bool m_bVideoExportMode;
    float m_fInfoUpdate;
    bool m_bShowInfoUpdateWarning;
    ZString m_sBuildVersion;
    bool m_bBuildIdSetup;
    bool m_bShowWorstCaseMemoryStats;
    SInfoText m_FpsText;
    SInfoText m_BuildVersionAndFingerPrintText;
    SInfoText m_PageMemoryText;
    SInfoText m_GPUMemoryText;
    SInfoText m_SubAllocatorHeadline;
    SInfoText m_SubAllocText[15];
    bool m_bFirstRun;
};
