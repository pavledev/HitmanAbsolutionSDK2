#pragma once

#include "IWaveBankData.h"
#include "ZWaveBankFSBData.h"
#include "SWaveBankResourceData.h"

class ZWaveBankData : public IWaveBankData
{
public:
    TResourcePtr<ZWaveBankFSBData> m_pRAMResource;
    TResourcePtr<SWaveBankFXData> m_pFXResource;
    TSharedPointer<ZResourceReader> m_pReader;
    const SWaveBankResourceData* m_pData;
    ZRuntimeResourceID m_resourceID;
};
