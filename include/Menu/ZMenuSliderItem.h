#pragma once

#include "ZMenuItem.h"
#include "EUIText.h"
#include "ZString.h"

class IScaleformExternalInterfaceArguments;
class ZVariant;
template <class A, class B> class TMap;

class ZMenuSliderItem : public ZMenuItem
{
public:
	unsigned short m_nOptionKey;
	float m_fMinValue;
	float m_fMaxValue;
	float m_fStepSize;
	float m_fValue;
	ZString m_sText;

	~ZMenuSliderItem() override = default;
	void GetInfo(TMap<ZString, ZVariant>& pInfo) override;
	void ExecuteAction(IScaleformExternalInterfaceArguments& params) override;

	ZMenuSliderItem() = default;
	ZMenuSliderItem(EUIText eTextId, unsigned short nOptionKey, float fMinValue, float fMaxValue, float fStepSize);
	ZMenuSliderItem(const char* szText, unsigned short nOptionKey, float fMinValue, float fMaxValue, float fStepSize);
	float GetValue();
	void SetValue(float val);
};
