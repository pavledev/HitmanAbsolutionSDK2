#pragma once

#include "TSharedPointer.h"
#include "ZResourceReader.h"

class ZWaveBankFSBData
{
public:
    TSharedPointer<ZResourceReader> m_pReader;
    const void* m_pSoundData;
    unsigned int m_nSoundSize;
};
