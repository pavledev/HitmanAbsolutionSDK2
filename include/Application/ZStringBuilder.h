#pragma once

#include "TArray.h"

class ZString;

class ZStringBuilder
{
public:
	TArray<char> m_chars;

	static void RegisterType();
	ZStringBuilder(const ZStringBuilder& rhs);
	ZStringBuilder(const char* pszInitial, int nLength);
	ZStringBuilder(const ZString& sInitial);
	ZStringBuilder() = default;
	~ZStringBuilder() = default;
	ZStringBuilder& operator=(const ZStringBuilder& rhs);
	const char& operator[](int nIndex) const;
	char& operator[](int nIndex);
	int Length() const;
	bool IsEmpty() const;
	void Clear();
	bool BeginsWith(const char* pszData) const;
	bool BeginsWith(const ZString& sData) const;
	bool BeginsWith(const char cData) const;
	bool EndsWith(const char* pszData) const;
	bool EndsWith(const ZString& sData) const;
	bool EndsWith(const char cData) const;
	int IndexOf(const char* pszData, int nStartPosition) const;
	int IndexOf(const ZString& sData, int nStartPosition) const;
	int IndexOf(const char cData, int nStartPosition) const;
	int LastIndexOf(const char* pszData, int nStartPosition) const;
	int LastIndexOf(const ZString& sData, int nStartPosition) const;
	int LastIndexOf(const char cData, int nStartPosition) const;
	void Trim();
	void Append(const char* pszData, int nLength);
	void Append(const ZString& sData);
	void Append(const char cData);
	void Prepend(const char* pszData, int nLength);
	void Prepend(const ZString& sData);
	void Prepend(const char cData);
	void Insert(const char* pszData, int nPosition, int nLength);
	void Insert(const ZString& sData, int nPosition);
	void Remove(int nStart, int nLength);
	void Replace(const char* pszMatch, const char* pszReplacement);
	void Replace(const char* pszMatch, const ZString& sReplacement);
	void Replace(const ZString& sMatch, const char* pszReplacement);
	void Replace(const ZString& sMatch, const ZString& sReplacement);
	void Replace(int nStart, int nLength, const char* pszReplacement);
	void Replace(int nStart, int nLength, const ZString& sReplacement);
	void Replace(char cMatch, char cReplacement);
	void ToLower();
	void ToUpper();
	ZString SubString(int nStart, int nLength) const;
	ZString ToString() const;
	void Initialize(const char* pszData, int nLength);
	int IndexOfInternal(const char* pszData, int nDataLength, int nStartPosition) const;
	int LastIndexOfInternal(const char* pszData, int nDataLength, int nStartPosition) const;
	void ReplaceInternal(const char* pszMatch, int nMatchLength, const char* sReplacement, int nReplaceLength);
};
