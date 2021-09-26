#pragma once

#include "TFixedArray.h"
#include "EHUDFadeReason.h"
#include "EHUDElement.h"

class ZHM5HUDFadeHandler
{
public:
	TFixedArray<unsigned int, 6> m_iFadeFlags;
	unsigned int m_iVisible;

	ZHM5HUDFadeHandler() = default;
	~ZHM5HUDFadeHandler() = default;
	void Reset();
	void ChangeFadeElements(unsigned int iElements, EHUDFadeReason eReason, bool bFadeIn, unsigned int& iToFadeIn, unsigned int& iToFadeOut);
	bool IsDisabledBy(EHUDFadeReason eReason, EHUDElement eElem) const;
};
