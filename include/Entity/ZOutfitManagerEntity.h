#pragma once

#include "ZEntityImpl.h"
#include "TEntityRef.h"
#include "ZHM5Outfit.h"
#include "ZComponentCreateInfo.h"
#include "Function.h"
#include "BaseAddresses.h"

class ZOutfitManagerEntity : public ZEntityImpl
{
public:
    TArray<TEntityRef<ZHM5Outfit>> m_Outfits;

    virtual ~ZOutfitManagerEntity();
    virtual ZVariantRef* GetVariantRef(ZVariantRef* result);
    virtual int AddRef();
    virtual int Release();
    virtual void* QueryInterface(STypeID* iid);
    virtual void Activate(ZString* sSubset);
    virtual void Deactivate(ZString* sSubset);
    virtual void Init();

    TEntityRef<ZHM5Outfit>* GetOutfit(TEntityRef<ZHM5Outfit>* result, STokenID outfitToken);
    //TEntityRef<ZHM5Outfit> GetOutfit(STokenID outfitToken);
    static void RegisterType();
    ZOutfitManagerEntity(ZComponentCreateInfo* pInfo);
};
