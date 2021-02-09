#pragma once

#include "IComponentInterface.h"
#include "TMap.h"
#include "ESingletonIconType.h"
#include "ZRuntimeResourceID.h"
#include "TFixedArray.h"
#include "ZDynamicResourceLibrary.h"
#include "TQueue.h"

class alignas(4) SLoaderLib
{
public:
    ZRuntimeResourceID m_ResourceID;
    ZDynamicResourceLibrary* m_pLib;
    __int16 m_iRefCount;
    bool m_bMarkedForDeletion;
};

class ZHM5IconLoader : public IComponentInterface
{
public:
    TMap<ESingletonIconType, ZRuntimeResourceID> m_pSingletonIcons;
    TFixedArray<SLoaderLib, 414> m_LoaderLibs;
    TQueue<int, TBlockArray<int>> m_LoadingQueue;

    enum
    {
        TECHNIQUEIDS = 0x1E,
        CPIMAGESIDS = 0x40,
        OUTFITSIDS = 0x64,
        CHALLENGESIDS = 0x50,
        WEAPONSIDS = 0x50,
        RATINGSIDS = 0x3C,
        TOTALIDS = 0x19E,
    };
};
