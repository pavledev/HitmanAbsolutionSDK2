#pragma once

union ValueUnion
{
    float NValue;
    bool BValue;
    const char* pString;
    const char** pStringManaged;
    const wchar_t* pStringW;
    void* pData;
};
