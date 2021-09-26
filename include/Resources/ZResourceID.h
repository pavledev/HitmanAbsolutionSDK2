#pragma once

#include "ZString.h"
#include "TEnumerator.h"

class ZResourceID
{
public:
	ZString m_uri;

	static void RegisterType();
	ZResourceID(const ZString& rhs);
	ZResourceID(const ZResourceID& rhs);
	ZResourceID() = default;
	ZResourceID& operator=(const ZResourceID& rhs);
	bool operator==(const ZResourceID& rhs) const;
	bool IsValid() const;
	bool IsEmpty() const;
	bool IsDerived() const;
	bool IsLibraryResource() const;
	bool IsLibrary() const;
	int GetIndexInLibrary() const;
	ZString GetExtension() const;
	ZString GetAllExtensions() const;
	ZString GetPlatformNeutralExtension() const;
	ZString GetPlatformFromExtension() const;
	ZResourceID ReplaceProtocol(const ZString& sProtocol) const;
	ZResourceID ReplacePlatform(const ZString& sTargetPlatform) const;
	ZResourceID ReplaceExtension(const ZString& sExtension) const;
	ZResourceID ReplacePlaformNeutralExtension(const ZString& sExtension) const;
	ZResourceID ReplaceRootPath(const ZString& sRootPath) const;
	ZResourceID ReplaceRootParameters(const ZString& sRootParameters) const;
	ZResourceID ReplaceCharacteristicName(const ZString& sCharacteristicName) const;
	bool FromString(const ZString& sSource);
	ZString ToString() const;
	unsigned int ToCString(char* pBuffer, unsigned int nSize, const ZString& sFormat) const;
	ZResourceID GetRoot() const;
	ZString GetProtocolName() const;
	ZString GetRootPath() const;
	ZString GetRootExtension() const;
	ZString GetRootParameters() const;
	ZString GetCharacteristicName() const;
	ZResourceID CreateDerivedResourceID(const ZString& sExtension, const ZString& sParameters, const ZString& sPlatform) const;
	ZResourceID GetSourceResourceID() const;
	ZResourceID GetInnermostSourceResourceID() const;
	TEnumerator<ZString> GetParameters() const;
	int GetParameterCount() const;
	ZString GetParameter(int nIndex) const;
	ZResourceID ReplaceParameters(const ZString& sParameters) const;
	ZString GetStrippedName() const;
	static int FindMatchingParentheses(const ZString& str, int startIndex, char open, char close);
	int GetDerivedEndIndex() const;
	~ZResourceID() = default;
};
