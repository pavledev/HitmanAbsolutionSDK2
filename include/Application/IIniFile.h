#pragma once

#include "IComponentInterface.h"
#include "ZFilePath.h"
#include "IIniFileSection.h"

class IIniFile : public IComponentInterface
{
public:
    virtual bool Load(const ZFilePath*);
    virtual bool LoadFromString(const ZString*);
    virtual IIniFileSection* GetSection(const ZString*);
    virtual TEnumerator<IIniFileSection*>* GetSections(TEnumerator<IIniFileSection*>* result);
    virtual ZString* GetValue(ZString* result, const ZString*, const ZString*);
    virtual void SetValue(const ZString*, const ZString*, const ZString*);
    virtual TEnumerator<ZString>* GetConsoleCmds(TEnumerator<ZString>* result);
};
