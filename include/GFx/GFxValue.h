#pragma once

#include "GNewOverrideBase.h"

class GFxMovieRoot;

class GFxValue
{
public:
	enum ValueTypeControl
	{
		VTC_ConvertBit = 128,
		VTC_ManagedBit = 64,
		VTC_TypeMask = 143
	};

	enum ValueType
	{
		VT_Undefined = 0,
		VT_Null = 1,
		VT_Boolean = 2,
		VT_Number = 3,
		VT_String = 4,
		VT_StringW = 5,
		VT_Object = 6,
		VT_Array = 7,
		VT_DisplayObject = 8,
		VT_ConvertBoolean = 130,
		VT_ConvertNumber = 131,
		VT_ConvertString = 132,
		VT_ConvertStringW = 133
	};

	class DisplayInfo
	{
	public:
		enum Flags
		{
			V_x = 1,
			V_y = 2,
			V_rotation = 4,
			V_xscale = 8,
			V_yscale = 16,
			V_alpha = 32,
			V_visible = 64,
			V_z = 128,
			V_xrotation = 256,
			V_yrotation = 512,
			V_zscale = 1024,
			V_perspFOV = 2048,
			V_perspMatrix3D = 4096,
			V_viewMatrix3D = 8192
		};

		float X;
		float Y;
		float Rotation;
		float XScale;
		float YScale;
		float Alpha;
		bool Visible;
		unsigned short VarsSet;

		DisplayInfo() = default;
		void SetX(float x);
		void SetY(float y);
		void SetRotation(float degrees);
		void SetAlpha(float alpha);
		void SetVisible(bool visible);
		bool GetVisible() const;
		void SetFlags(unsigned int flags);
	};

	class ObjectInterface : public GNewOverrideBase<326>
	{
	public:
		class __declspec(novtable) ObjVisitor
		{
		public:
			virtual ~ObjVisitor() = default;
			virtual void Visit(const char* param1, const GFxValue& fxValue) = 0;

			ObjVisitor() = default;
		};

		class __declspec(novtable) ArrVisitor
		{
		public:
			virtual ~ArrVisitor() = default;
			virtual void Visit(unsigned int param1, const GFxValue& fxValue) = 0;

			ArrVisitor() = default;
		};

		GFxMovieRoot* pMovieRoot;
	};

	class __declspec(novtable) ObjectVisitor
	{
	public:
		virtual ~ObjectVisitor() = default;
		virtual void Visit(const char* param1, const GFxValue& fxValue) = 0;

		ObjectVisitor() = default;
	};

	class __declspec(novtable) ArrayVisitor
	{
	public:
		virtual ~ArrayVisitor() = default;
		virtual void Visit(unsigned int param1, const GFxValue& fxValue) = 0;

		ArrayVisitor() = default;
	};

	union ValueUnion
	{
		float NValue;
		bool BValue;
		const char* pString;
		const char** pStringManaged;
		const wchar_t* pStringW;
		void* pData;
	};

	ObjectInterface* pObjectInterface;
	ValueType Type;
	ValueUnion Value;

	GFxValue(const GFxValue& src);
	GFxValue(const char* ps);
	GFxValue(bool v);
	GFxValue(float v);
	GFxValue() = default;
	~GFxValue() = default;
	const GFxValue& operator=(const GFxValue& src);
	ValueType GetType() const;
	bool IsUndefined() const;
	bool IsNull() const;
	bool IsNumber() const;
	bool IsDisplayObject() const;
	bool GetBool() const;
	float GetNumber() const;
	void SetUndefined();
	void SetNull();
	void SetNumber(float v);
	void SetString(const char* p);
	bool HasMember(const char* name) const;
	bool GetMember(const char* name, GFxValue* pval) const;
	bool SetMember(const char* name, const GFxValue& val);
	bool GetElement(unsigned int idx, GFxValue* pval) const;
	bool GetDisplayInfo(DisplayInfo* pinfo) const;
	bool SetDisplayInfo(const DisplayInfo& info);
	bool SetText(const char* ptext);
	bool SetTextHTML(const char* phtml);
	bool GotoAndPlay(unsigned int frame);
	bool GotoAndPlay(const char* frame);
	bool GotoAndStop(unsigned int frame);
	bool GotoAndStop(const char* frame);
	bool IsManagedValue() const;
	void ChangeType(ValueType type);
	void AcquireManagedValue(const GFxValue& src);
	void ReleaseManagedValue();
};
