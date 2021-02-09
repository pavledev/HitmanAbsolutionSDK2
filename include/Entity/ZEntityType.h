#pragma once

#include "TArray.h"
#include "SPropertyData.h"
#include "SInterfaceData.h"
#include "SExposedEntityData.h"
#include "SSubsetData.h"
#include "SPinData.h"
#include "ZEventNull.h"
#include "ZEvent.h"

class ZEntityRef;

class ZEntityType
{
public:
    int m_nBorrowedPointersMask;
    TArray<SPropertyData>* m_pPropertyData;
    TArray<SInterfaceData>* m_pInterfaceData;
    TArray<SExposedEntityData>* m_pExposedEntityData;
    TArray<SSubsetData>* m_pSubsets;
    TArray<SPinData>* m_pInputPins;
    TArray<SPinData>* m_pOutputPins;
    ZEvent<ZEntityRef const&, ZEventNull, ZEventNull, ZEventNull, ZEventNull>* m_pDeletionListeners;
};
