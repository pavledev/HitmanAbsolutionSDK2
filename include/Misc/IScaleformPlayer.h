#pragma once

#include "IComponentInterface.h"
#include "GFxValue.h"
#include "EScaleMode.h"
#include "GFxEvent.h"
#include "ZEvent.h"
#include "ZEventNull.h"
#include "GFxFunctionHandler.h"
#include "ZRenderContext.h"

class IScaleformPlayer : public IComponentInterface
{
public:
    virtual void Advance(float);
    virtual void UpdateDisplay(ZRenderContext*);
    virtual void UpdateWindowSize(unsigned int, unsigned int, float);
    virtual void SetVariableValue(const ZString*, const ZVariantRef*);
    virtual ZString* GetVariableValue(ZString* result, const ZString*);
    virtual void CallFunction(const ZString*, const ZVariantRef*, const ZVariantRef*, const ZVariantRef*, const ZVariantRef*, const ZVariantRef*, const ZVariantRef*, const ZVariantRef*, const ZVariantRef*, const ZVariantRef*, const ZVariantRef*);
    virtual void CallFunctionFromThread(const ZString*, const ZVariantRef*, const ZVariantRef*, const ZVariantRef*, const ZVariantRef*, const ZVariantRef*, const ZVariantRef*, const ZVariantRef*, const ZVariantRef*, const ZVariantRef*, const ZVariantRef*);
    virtual GFxValue* CallFunctionWithReturnValue(GFxValue* result, const ZString*, const ZVariantRef*, const ZVariantRef*, const ZVariantRef*, const ZVariantRef*, const ZVariantRef*, const ZVariantRef*, const ZVariantRef*, const ZVariantRef*, const ZVariantRef*, const ZVariantRef*);
    virtual int GetLayer();
    virtual void SetScaleMode(EScaleMode);
    virtual const ZString* GetMovieName(const ZString* result);
    virtual bool GetMember(const char*, GFxValue*);
    virtual bool GetMember(const ZString*, GFxValue*);
    virtual void SetSafeArea(int, int);
    virtual void HandleEvent(const GFxEvent*);
    virtual bool IsReady();
    virtual ZEvent<ZEventNull, ZEventNull, ZEventNull, ZEventNull, ZEventNull>* GetResourceChangedEvent();
    virtual void MaintainAspectRatio(bool);
    virtual bool CreateFunction(GFxValue*, GFxFunctionHandler*);
    virtual bool CreateTween(const ZString*, float, float, float, const ZString*);
    virtual bool KillTween(const ZString*);
    virtual bool AdvanceOnRenderThread();
    virtual void SetPrimaryMonitorOnly(bool);
    virtual void SetMovieClipDepth(ZString, float);
    virtual void RemoveMovieClipDepth(ZString);
};
