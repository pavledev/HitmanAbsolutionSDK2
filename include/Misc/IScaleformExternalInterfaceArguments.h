#pragma once

#include "ZVariant.h"
#include "TArray.h"
#include "ZVariantRef.h"
#include "ZString.h"

class GFxMovieView;
class GFxValue;
class IScaleformExternalInterfaceHandler;
template <class A, class B> class TMap;

class __declspec(novtable) IScaleformExternalInterfaceArguments
{
public:
	virtual ~IScaleformExternalInterfaceArguments() = default;
	virtual ZVariant operator[](int param1) const = 0;
	virtual int Count() const = 0;
	virtual int GetInt(int param1) = 0;
	virtual float GetFloat(int param1) = 0;
	virtual bool GetBool(int param1) = 0;
	virtual ZString GetString(int param1) = 0;
	virtual bool IsDefined(int param1) = 0;
	virtual const GFxValue* GetGFxValuePtr(int param1) = 0;
	virtual bool HasString(int param1) = 0;
	virtual TArray<int> GetIntArray(int param1) = 0;
	virtual TArray<unsigned int> GetUIntArray(int param1) = 0;
	virtual TArray<ZString> GetStringArray(int param1) = 0;
	virtual void SetReturnValues(const TArray<ZString>& array) = 0;
	virtual void SetReturnValues(const TArray<TMap<ZString, ZVariant>>& array) = 0;
	virtual void SetReturnValues(const TArray<ZVariantRef>& array) = 0;
	virtual void SetReturnValue(const ZVariantRef variantRef) = 0;
	virtual void SetReturnValue(const TMap<ZString, ZVariant>& map) = 0;
	virtual IScaleformExternalInterfaceHandler* GetHandler() const = 0;
	virtual GFxMovieView* GetMovieView() const = 0;

	IScaleformExternalInterfaceArguments() = default;
};
