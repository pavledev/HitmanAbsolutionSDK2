#pragma once

#include "THashMap.h"
#include "ZString.h"

class ZResourcePending;
template <class A, class B> class TDefaultHashMapPolicy;

class ZTextListData
{
public:
	THashMap<int, ZString, TDefaultHashMapPolicy<int, ZString>> m_Map;
	bool m_bUsingGamepad;

	ZTextListData() = default;
	ZTextListData(const ZTextListData& __that);
	ZTextListData(ZResourcePending& resourcePending);
	~ZTextListData() = default;
	bool TryGetText(const ZString& sName, ZString& sText) const;
	bool TryGetText(int nNameHash, ZString& sText, const ZString& sErrorText, bool bSuppressErrorReporting, bool bTryPCTextList) const;
	ZString GetText(const ZString& sName) const;
	ZString GetText(int nNameHash, const ZString& sErrorText) const;
	const THashMap<int, ZString, TDefaultHashMapPolicy<int, ZString>>& GetMap() const;
	ZString GetTextForNonlocalizedUse(const ZString& sName) const;
	static void ReportError(int nNameHash, const ZString& sErrorText, ZString& sResultText);
	void setUsingGamepad(const bool bUsingGamepad);
	ZTextListData& operator=(const ZTextListData& __that);
};
