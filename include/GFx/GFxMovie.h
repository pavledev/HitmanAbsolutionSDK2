#pragma once

#include "GRefCountBase.h"

class GFxMovieDef;
class GFxFunctionHandler;
class GFxValue;

class __declspec(novtable) GFxMovie : public GRefCountBase<GFxMovie, 326>
{
public:
	enum PlayState
	{
		Playing = 0,
		Stopped = 1
	};

	enum SetVarType
	{
		SV_Normal = 0,
		SV_Sticky = 1,
		SV_Permanent = 2
	};

	enum SetArrayType
	{
		SA_Int = 0,
		SA_Double = 1,
		SA_Float = 2,
		SA_String = 3,
		SA_StringW = 4,
		SA_Value = 5
	};

	~GFxMovie() override = default;
	virtual GFxMovieDef* GetMovieDef() const = 0;
	virtual unsigned int GetCurrentFrame() const = 0;
	virtual bool HasLooped() const = 0;
	virtual void GotoFrame(unsigned int param1) = 0;
	virtual bool GotoLabeledFrame(const char* param1, int param2) = 0;
	virtual void SetPlayState(PlayState playState) = 0;
	virtual PlayState GetPlayState() const = 0;
	virtual void SetVisible(bool param1) = 0;
	virtual bool GetVisible() const = 0;
	virtual bool IsAvailable(const char* param1) const = 0;
	virtual void CreateString(GFxValue* fxValue, const char* param2) = 0;
	virtual void CreateStringW(GFxValue* fxValue, const wchar_t* param2) = 0;
	virtual void CreateObject(GFxValue* fxValue, const char* param2, const GFxValue* fxValue3, unsigned int param4) = 0;
	virtual void CreateArray(GFxValue* fxValue) = 0;
	virtual void CreateFunction(GFxValue* fxValue, GFxFunctionHandler* fxFunctionHandler, void* param3) = 0;
	virtual bool SetVariable(const char* param1, const GFxValue& fxValue, SetVarType setVarType) = 0;
	virtual bool GetVariable(GFxValue* fxValue, const char* param2) const = 0;
	virtual bool SetVariableArray(SetArrayType setArrayType, const char* param2, unsigned int param3, const void* param4, unsigned int param5, SetVarType setVarType) = 0;
	virtual bool SetVariableArraySize(const char* param1, unsigned int param2, SetVarType setVarType) = 0;
	virtual unsigned int GetVariableArraySize(const char* param1) = 0;
	virtual bool GetVariableArray(SetArrayType setArrayType, const char* param2, unsigned int param3, void* param4, unsigned int param5) = 0;
	virtual bool Invoke(const char* param1, GFxValue* fxValue, const char* param3, ...) = 0;
	virtual bool Invoke(const char* param1, GFxValue* fxValue, const GFxValue* fxValue3, unsigned int param4) = 0;
	virtual bool InvokeArgs(const char* param1, GFxValue* fxValue, const char* param3, char* param4) = 0;

	bool SetVariableDouble(const char* ppathToVar, float value, SetVarType setType);
	GFxMovie() = default;
};
