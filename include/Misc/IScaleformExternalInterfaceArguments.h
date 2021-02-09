#pragma once

#include "ZVariant.h"
#include "GFxValue.h"
#include "TArray.h"
#include "TMap.h"
#include "ZVariantRef.h"
#include "IScaleformExternalInterfaceHandler.h"
#include "GFxMovieView.h"

class IScaleformExternalInterfaceArguments
{
public:
    virtual ~IScaleformExternalInterfaceArguments();
    //virtual ZVariant* operator[](ZVariant* result, int); //original
    virtual ZVariant operator[](int); //??? check
    virtual int Count();
    virtual int GetInt(int);
    virtual float GetFloat(int);
    virtual bool GetBool(int);
    virtual ZString* GetString(ZString* result, int);
    virtual bool IsDefined(int);
    virtual const GFxValue* GetGFxValuePtr(int);
    virtual bool HasString(int);
    virtual TArray<int>* GetIntArray(TArray<int>* result, int);
    virtual TArray<unsigned int>* GetUIntArray(TArray<unsigned int>* result, int);
    virtual TArray<ZString>* GetStringArray(TArray<ZString>* result, int);
    virtual void SetReturnValues(const TArray<ZString>*);
    virtual void SetReturnValues(const TArray<TMap<ZString, ZVariant> >*);
    virtual void SetReturnValues(const TArray<ZVariantRef>*);
    virtual void SetReturnValue(const ZVariantRef);
    virtual void SetReturnValue(const TMap<ZString, ZVariant>*);
    virtual IScaleformExternalInterfaceHandler* GetHandler();
    virtual GFxMovieView* GetMovieView();
};
