#pragma once

#include "TEntityRef.h"

class ZHitman5;

class ZHM5FocusController
{
public:
	bool m_bIsGaining;
	float m_fFocusGainTechniqueModifier;
	float m_fFocusMaxTechniqueModifier;
	float* m_pFocus;
	float m_fAdjustFocus;
	float m_fPendingMinFocus;
	float m_fPendingFocus;
	TEntityRef<ZHitman5> m_pHitman;

	static const float m_sfDefaultFocus;

	ZHM5FocusController() = default;
	ZHM5FocusController(const TEntityRef<ZHitman5>& pHitman);
	~ZHM5FocusController() = default;
	void UpdateFocus();
	float GetCurrentFocus() const;
	float GetMaxFocus() const;
	void AddFocus(float fDelta);
	void SetMinFocus(float fMinFocus);
	void SetFocus(float fFocus);
	void ClearFocus();
	void WipeFocus();
	float GetBurndownRate();
	bool IsFocusGaining();
	void SetFocusTechniqueModifiers(float fValGain, float fValMax);
};
