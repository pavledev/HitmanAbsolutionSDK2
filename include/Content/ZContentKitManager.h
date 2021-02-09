#pragma once

#include "IComponentInterface.h"
#include "ZContentKitList.h"
#include "ZFireArmKitEntity.h"
#include "ZFireArmKitMenuSetup.h"
#include "SFireArmKitSaveData.h"
#include "SFireArmKitState.h"
#include "ZOutfitKitEntity.h"
#include "ZOutfitKitMenuSetup.h"
#include "SOutfitKitSaveData.h"
#include "ZPropKitEntity.h"
#include "ZPropKitMenuSetup.h"
#include "SPropKitSaveData.h"
#include "SPropKitState.h"
#include "ZContentKitDLCInfo.h"
#include "SRuntimeItemResource.h"
#include "ZGlobalOutfitKit.h"
#include "ZGlobalItemKit.h"
#include "ZDLCDescriptor.h"

class ZContentKitManager : public IComponentInterface
{
public:
    ZContentKitList<ZFireArmKitEntity, ZFireArmKitMenuSetup, SFireArmKitSaveData, SFireArmKitState> m_FireArms;
    ZContentKitList<ZOutfitKitEntity, ZOutfitKitMenuSetup, SOutfitKitSaveData, SOutfitKitState> m_Outfits;
    ZContentKitList<ZPropKitEntity, ZPropKitMenuSetup, SPropKitSaveData, SPropKitState> m_Props;
    TMap<STokenID const, TEntityRef<ZContentKitDLCInfo>> m_KitDLCInfos;
    TMap<STokenID const, SRuntimeItemResource> m_RuntimeItemResources;
    TMap<STokenID const, TEntityRef<ZGlobalOutfitKit>> m_GlobalOutfitKits;
    TMap<STokenID const, TEntityRef<ZGlobalItemKit>> m_GlobalItemKits;
    TArray<TEntityRef<ZDLCDescriptor>> m_DLCDescriptors;
    TArray<STokenID> m_DLCUnlocksGranted;
};
