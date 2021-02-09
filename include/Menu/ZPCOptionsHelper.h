#pragma once

#include "ZMenuSpinnerItem.h"
#include "ZMenuToggleItem.h"
#include "ZMenuPCEventItem.h"
#include "ZMenuSliderItem.h"

class ZPCOptionsHelper
{
public:
    ZMenuSpinnerItem* m_pResolutionSpinner;
    ZMenuSpinnerItem* m_pRefreshRateSpinner;
    ZMenuToggleItem* m_pFullscreenToggle;
    ZMenuToggleItem* m_pExclusiveToggle;
    ZMenuToggleItem* m_pVSyncToggle;
    ZMenuSpinnerItem* m_pMonitorSpinner;
    ZMenuToggleItem* m_pStereoscopicToggle;
    ZMenuPCEventItem* m_pApplyPCEvent;
    ZMenuSpinnerItem* m_pAspectSpinner;
    ZMenuSliderItem* m_pGammaSlider;
    ZMenuSliderItem* m_pStereoDepthSlider;
    ZMenuSliderItem* m_pStereoStrengthSlider;
    ZMenuSpinnerItem* m_pMSAASpinner;
    ZMenuSpinnerItem* m_pQualitySpinner;
    ZMenuSpinnerItem* m_pShadowQualitySpinner;
    ZMenuSpinnerItem* m_pTextureResolutionSpinner;
    ZMenuSpinnerItem* m_pTextureFilterSpinner;
    ZMenuSpinnerItem* m_pSSAOSpinner;
    ZMenuToggleItem* m_pSSGIToggle;
    ZMenuToggleItem* m_pLPVToggle;
    ZMenuSpinnerItem* m_pTessellationSpinner;
    ZMenuSpinnerItem* m_pMirrorQualitySpinner;
    ZMenuSpinnerItem* m_pAntiAliasingSpinner;
    ZMenuSpinnerItem* m_pLevelOfDetailSpinner;
    ZMenuSpinnerItem* m_pBokehSpinner;
    ZMenuSpinnerItem* m_pBloomSpinner;
    ZMenuPCEventItem* m_pResetPCEvent;
    ZMenuItem* m_pGamePadOptions;
    ZMenuPCEventItem* m_pGamePadLayout;
    ZMenuPCEventItem* m_pButtonMapping;
};
