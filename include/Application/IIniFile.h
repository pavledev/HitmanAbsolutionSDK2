#pragma once

#include "IComponentInterface.h"
#include "ZFilePath.h"
#include "TEnumerator.h"
#include "ZString.h"

class IIniFileSection;

class __declspec(novtable) IIniFile : public IComponentInterface
{
public:
	~IIniFile() override = default;
	virtual bool Load(const ZFilePath& filePath) = 0;
	virtual bool LoadFromString(const ZString& string) = 0;
	virtual IIniFileSection* GetSection(const ZString& string) = 0;
	virtual TEnumerator<IIniFileSection*> GetSections() = 0;
	virtual ZString GetValue(const ZString& string, const ZString& string2) = 0;
	virtual void SetValue(const ZString& string, const ZString& string2, const ZString& string3) = 0;
	virtual TEnumerator<ZString> GetConsoleCmds() = 0;

	IIniFile() = default;
};
