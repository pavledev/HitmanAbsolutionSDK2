#pragma once

#include "ZGraphicsSettingsManager.h"
#include "EUIMenuItemName.h"
#include "EUIText.h"

class ZMenuItem;
class ZMenuPCEventItem;
class ZMenuSliderItem;
class ZMenuSpinnerItem;
class ZMenuToggleItem;

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

	ZPCOptionsHelper() = default;
	~ZPCOptionsHelper() = default;
	void SyncAllDisplayOptions();
	void SyncAllQualityOptions();
	void SyncSpinnerMenuItem(ZMenuSpinnerItem* pSpinner, const ZGraphicsSettingsManager::QualityOption* options, unsigned int nOptionCount, unsigned int nCurrentIdx, bool bPermanentlyDisabled, EUIText eDisabledText);
	void SyncMenuItemStates();
	void Shutdown();
	ZMenuItem* GetMenuItem(EUIMenuItemName eMenuItem);
	ZMenuSpinnerItem* GetMenuSpinnerItem(EUIMenuItemName eMenuItem);
	ZMenuToggleItem* GetMenuToggleItem(EUIMenuItemName eMenuItem);
	void SetMenuItemEnabled(EUIMenuItemName eMenuItem, bool bEnabled);
	bool IsMenuItemDisabled(EUIMenuItemName eMenuItem);
	bool CanApplyDisplaySettings();
};
