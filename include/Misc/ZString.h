#pragma once

#include "TArray.h"

class ZVariantRef;
template <class T> class TArrayRef;

class ZString
{
public:
	class ZImpl
	{
	public:
		unsigned int m_nAllocatedSize;
		long m_nRefcount;
		ZImpl* m_pNext;

		static ZImpl* Allocate(const char* pszString, unsigned int nStringLength);
		void Free();
		void Addref() const;
		char* GetChars();
		unsigned int GetAllocatedSize() const;
	};

	unsigned int m_length;
	const char* m_chars;

	static const unsigned int STATIC_STRING;
	static const unsigned int VOLATILE_STRING;
	static const unsigned int FLAGS_MASK;

	ZString(ZImpl* pImpl, unsigned int nLength);
	ZString(const ZString& rhs);
	ZString() = default;
	~ZString() = default;
	static ZString ReferenceCString(const char* pStringLiteral, unsigned int nLength);
	static ZString ReferenceCString(const char* pStringLiteral);
	static ZString AllocateFromCString(const char* rhs, int maxLength);
	static ZString AllocateFromCString(const char* rhs);
	static ZString AllocateFromWchar(const wchar_t* pwzString);
	static ZString AllocateFromCArray(const char* rhs, int length);
	ZString& operator=(const ZString& rhs);
	bool operator==(const char* rhs) const;
	bool operator==(const ZString& rhs) const;
	bool operator!=(const char* rhs) const;
	bool operator!=(const ZString& rhs) const;
	bool operator<(const char* rhs) const;
	bool operator<(const ZString& rhs) const;
	bool operator>(const char* rhs) const;
	bool operator>(const ZString& rhs) const;
	char operator[](int index) const;
	ZString& operator+=(const char rhs);
	ZString& operator+=(const char* rhs);
	ZString& operator+=(const ZString& rhs);
	bool IsEmpty() const;
	int Length() const;
	int IndexOf(const char* rhs, int fromIndex) const;
	int IndexOf(const ZString& rhs, int fromIndex) const;
	int IndexOf(const char* rhs) const;
	int IndexOf(const ZString& rhs) const;
	int IndexOf(char c, int fromIndex) const;
	int IndexOf(char c) const;
	int LastIndexOf(char c, int fromIndex) const;
	int LastIndexOf(char c) const;
	int IIndexOf(const char* rhs, int fromIndex) const;
	int IIndexOf(const char* rhs) const;
	int IIndexOf(const ZString& rhs) const;
	bool StartsWith(const ZString& rhs) const;
	bool IStartsWith(const ZString& rhs) const;
	bool EndsWith(const char rhs) const;
	bool EndsWith(const ZString& rhs) const;
	bool IEndsWith(const ZString& rhs) const;
	int ICompare(const ZString& rhs) const;
	int IWCompare(const ZString& rhs) const;
	ZString Substring(int start, int length) const;
	ZString Append(const char rhs) const;
	ZString Append(const char* rhs) const;
	ZString Append(const ZString& string) const;
	ZString Prepend(const char rhs) const;
	ZString Prepend(const char* string) const;
	ZString Prepend(const ZString& string) const;
	ZString Replace(char match, char replacement) const;
	ZString ReplaceChar(int index, char replacement) const;
	ZString Remove(int nStart, int nLength) const;
	ZString Trim() const;
	ZString Insert(const ZString& sData, int nPosition) const;
	ZString ToLower() const;
	ZString ToUpper() const;
	const char* ToCString() const;
	static ZString Format(const ZString& sFormat, const ZVariantRef& a0__, const ZVariantRef& a1__, const ZVariantRef& a2__, const ZVariantRef& a3__, const ZVariantRef& a4__, const ZVariantRef& a5__, const ZVariantRef& a6__, const ZVariantRef& a7__);
	void FormatInplace(const ZString& sFormat, const ZVariantRef* aArgs, unsigned int nArgSize);
	void FormatInplace(const ZString& sFormat, const ZVariantRef& a0__, const ZVariantRef& a1__, const ZVariantRef& a2__, const ZVariantRef& a3__, const ZVariantRef& a4__, const ZVariantRef& a5__, const ZVariantRef& a6__, const ZVariantRef& a7__);
	static ZString FormatOld(const ZString& sFormat, const ZVariantRef* aArgs, unsigned int nArgs);
	TArray<ZString> Split(char delimiter) const;
	int FindMatchingParentheses(int startIndex, const ZString& parentheses) const;
	int FindNextSplit(int startIndex, char seperator, const ZString& parentheses) const;
	TArray<ZString> SplitWithParentheses(int startIndex, char seperator, const ZString& parentheses) const;
	static ZString Join(const ZString& sSeparator, TArrayRef<ZString> aValues);
	unsigned int GetHashCode() const;
	unsigned int GetCaseInsensitiveHashCode() const;
	void Free();
	const ZImpl* GetImpl() const;
	ZImpl* GetImpl();
};
