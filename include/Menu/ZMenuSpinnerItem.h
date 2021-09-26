#pragma once

#include "ZMenuItem.h"
#include "EUIText.h"
#include "TArray.h"
#include "ZString.h"

class IScaleformExternalInterfaceArguments;
class ZVariant;
template <class A, class B> class TMap;

class ZMenuSpinnerItem : public ZMenuItem
{
public:
	unsigned short m_nOptionKey;
	unsigned int m_nCurrentIdx;
	TArray<ZString> m_sEntry;

	~ZMenuSpinnerItem() override = default;
	void GetInfo(TMap<ZString, ZVariant>& pInfo) override;
	void ExecuteAction(IScaleformExternalInterfaceArguments& params) override;

	ZMenuSpinnerItem() = default;
	ZMenuSpinnerItem(EUIText eTextID, unsigned short nOptionKey);
	void AddEntry(ZString szText);
	void AddEntry(const char* szText);
	ZString GetEntry(unsigned int nIndex);
	ZString GetCurrentEntry();
	void Clear();
	void SetCurrentIndex(unsigned int nCurrentIdx);
	unsigned int GetNumEntries();
};
