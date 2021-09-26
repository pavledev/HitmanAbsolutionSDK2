#pragma once

class ZDebugConsoleCompletionList
{
public:
	char* m_pBuffer;
	int m_iBufferSize;
	int m_iAllocPos;
	char** m_pszStrings;
	int m_iCount;
	char* m_szPrefix;

	ZDebugConsoleCompletionList() = default;
	ZDebugConsoleCompletionList(int iBufferSize);
	~ZDebugConsoleCompletionList() = default;
	void Add(const char* szComp);
	void Prefix(char* szPrefix);
	void Unique();
	void Sort();
	void Clear();
	int Count();
	char* Get(int iNr);
	void LongestCommonPrefix(char*& szStr, int& iLen);
	bool LTH(int i, int j);
	void Swap(int i, int j);
	void Heapify(int i);
};
