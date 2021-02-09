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
};
