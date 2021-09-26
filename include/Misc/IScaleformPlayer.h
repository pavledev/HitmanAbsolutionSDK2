#pragma once

#include "IComponentInterface.h"
#include "GFxValue.h"
#include "GFxEvent.h"
#include "ZString.h"
#include "ZVariantRef.h"

class GFxFunctionHandler;
class ZEventNull;
class ZRenderContext;
template <class A, class B, class C, class D, class E> class ZEvent;

class __declspec(novtable) IScaleformPlayer : public IComponentInterface
{
public:
	enum EScaleMode
	{
		NoScale = 0,
		ShowAll = 1,
		ExactFit = 2,
		NoBorder = 3
	};

	~IScaleformPlayer() override = default;
	virtual void Advance(float param1) = 0;
	virtual void UpdateDisplay(ZRenderContext* renderContext) = 0;
	virtual void UpdateWindowSize(unsigned int param1, unsigned int param2, float param3) = 0;
	virtual void SetVariableValue(const ZString& string, const ZVariantRef& variantRef) = 0;
	virtual ZString GetVariableValue(const ZString& string) = 0;
	virtual void CallFunction(const ZString& string, const ZVariantRef& variantRef, const ZVariantRef& variantRef3, const ZVariantRef& variantRef4, const ZVariantRef& variantRef5, const ZVariantRef& variantRef6, const ZVariantRef& variantRef7, const ZVariantRef& variantRef8, const ZVariantRef& variantRef9, const ZVariantRef& variantRef10, const ZVariantRef& variantRef11) = 0;
	virtual void CallFunctionFromThread(const ZString& string, const ZVariantRef& variantRef, const ZVariantRef& variantRef3, const ZVariantRef& variantRef4, const ZVariantRef& variantRef5, const ZVariantRef& variantRef6, const ZVariantRef& variantRef7, const ZVariantRef& variantRef8, const ZVariantRef& variantRef9, const ZVariantRef& variantRef10, const ZVariantRef& variantRef11) = 0;
	virtual GFxValue CallFunctionWithReturnValue(const ZString& string, const ZVariantRef& variantRef, const ZVariantRef& variantRef3, const ZVariantRef& variantRef4, const ZVariantRef& variantRef5, const ZVariantRef& variantRef6, const ZVariantRef& variantRef7, const ZVariantRef& variantRef8, const ZVariantRef& variantRef9, const ZVariantRef& variantRef10, const ZVariantRef& variantRef11) = 0;
	virtual int GetLayer() const = 0;
	virtual void SetScaleMode(EScaleMode scaleMode) = 0;
	virtual const ZString GetMovieName() = 0;
	virtual bool GetMember(const char* param1, GFxValue* fxValue) = 0;
	virtual bool GetMember(const ZString& string, GFxValue* fxValue) = 0;
	virtual void SetSafeArea(int param1, int param2) = 0;
	virtual void HandleEvent(const GFxEvent& fxEvent) = 0;
	virtual bool IsReady() const = 0;
	virtual ZEvent<ZEventNull, ZEventNull, ZEventNull, ZEventNull, ZEventNull>& GetResourceChangedEvent() = 0;
	virtual void MaintainAspectRatio(bool param1) = 0;
	virtual bool CreateFunction(GFxValue* fxValue, GFxFunctionHandler* fxFunctionHandler) = 0;
	virtual bool CreateTween(const ZString& string, float param2, float param3, float param4, const ZString& string5) = 0;
	virtual bool KillTween(const ZString& string) = 0;
	virtual bool AdvanceOnRenderThread() const = 0;
	virtual void SetPrimaryMonitorOnly(bool param1) = 0;
	virtual void SetMovieClipDepth(ZString string, float param2) = 0;
	virtual void RemoveMovieClipDepth(ZString string) = 0;

	static void RegisterType();
	IScaleformPlayer() = default;
};
