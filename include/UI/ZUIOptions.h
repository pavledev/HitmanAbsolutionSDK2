#pragma once

#include "IComponentInterface.h"
#include "Values.h"
#include "ESaveLoadSlotStatus.h"
#include "SComponentMapEntry.h"

class alignas(4) ZUIOptions : public IComponentInterface
{
public:
    Values<float> m_FloatValues;
    Values<int> m_IntValues;
    Values<bool> m_BoolValues;
    bool m_bLoaded;
    bool m_bDirty;

    virtual ~ZUIOptions();
    virtual ZVariantRef* GetVariantRef(ZVariantRef * result);
    virtual int AddRef();
    virtual int Release();
    virtual void* QueryInterface(STypeID * iid);

    int Int(unsigned int key);

    template<class T>
    void RegisterForOptionChange(_EUIOptionKey optionKey, ZDelegate<void __cdecl(T)> callback, unsigned int offset);

    template<class T>
    void UnregisterForOptionChange(_EUIOptionKey optionKey, ZDelegate<void __cdecl(T)> callback, unsigned int offset);

    float Float(unsigned int key);
    bool Bool(unsigned int key);
    void SetInt(unsigned int key, int value);

    template<class T>
    Values<T>* GetValues(unsigned int offset);

    void LoadDefaults();
    void WriteData();
    bool Save();
    void ReadData();
    void OnLoadDone(ESaveLoadSlotStatus eStatus);
    ZUIOptions();
    const SComponentMapEntry* GetComponentInterfacesInternal();
    void SetFloat(unsigned int key, float value);
    void SetBool(unsigned int key, bool value);
};
