#pragma once

#include "TArray.h"
#include "ZResourceStub.h"
#include "ZResourceID.h"
#include "SResourceLibraryEntry.h"

class ZResourceLibraryInfo
{
public:
    TArray<int> m_StreamingStates;
    ZResourceStub* m_pLibraryStub;
    ZResourceID m_ResourceID;
    ZRuntimeResourceID m_MapResourceID;
    ZRuntimeResourceID m_SourceResourceID;
    TArray<SResourceLibraryEntry> m_Entries;
    char m_Flags;
    unsigned int m_nStartFilePosition;
    TArray<unsigned int> m_EntryFilePositions;
    TArray<ZString> m_Languages;
    int m_LocalizationCategory;

    enum UnkEnum : unsigned __int32
    {
        GLOBAL_LIBRARIES_STATE = 0xFFFFFFFF,
        NON_STREAMED_LIBRARIES_STATE = 0xFFFFFFFE,
        INIT_LIBRARIES_STATE = 0xFFFFFFFD
    };
};
