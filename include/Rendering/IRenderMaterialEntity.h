#pragma once

#include "IComponentInterface.h"
#include "TArray.h"
#include "TArrayRef.h"
#include "ZResourcePtr.h"
#include "SColorRGBA.h"
#include "SColorRGB.h"
#include "SVector2.h"
#include "ZEntityRef.h"
#include "SVector3.h"
#include "SVector4.h"
#include "ZRuntimeResourceID.h"

class ZString;

class __declspec(novtable) IRenderMaterialEntity : public IComponentInterface
{
public:
	enum
	{
		MAX_TARGET_GEOMS = 5
	};

	enum EModifierOperation
	{
		eLeave = 0,
		eReplace = 1,
		eModulate = 2,
		eAdd = 3,
		eColor = 128
	};

	enum EModifierChangeFlag
	{
		eStructureChangeFlag = 1,
		eParameterChangeFlag = 2,
		eParameterTextureChangeFlag = 4
	};

	struct SModifierDesc
	{
		TArray<ZString> m_sTextureNames;
		TArray<ZString> m_sFloatNames;
		unsigned int m_nNumFloatNames;
		unsigned int m_nNumFloat2Names;
		unsigned int m_nNumFloat3Names;
		unsigned int m_nNumFloat4Names;
		TArray<ZString> m_sColorNames;
		unsigned int m_nNumColor3Names;
		unsigned int m_nNumColor4Names;

		SModifierDesc() = default;
		~SModifierDesc() = default;
	};

	struct SModifierValues
	{
		struct STextureModifier
		{
			bool m_bEnabled;
			ZRuntimeResourceID m_idTexture;
			int m_nFrameIndex;
			ZEntityRef m_RenderDestinationTexture;

			STextureModifier(const STextureModifier& __that);
			STextureModifier() = default;
			~STextureModifier() = default;
		};

		struct SFloatModifier
		{
			EModifierOperation m_eOperation;
			float m_Value;
		};

		struct SFloat2Modifier
		{
			EModifierOperation m_eOperation;
			SVector2 m_Value;
		};

		struct SFloat3Modifier
		{
			EModifierOperation m_eOperation;
			SVector3 m_Value;
		};

		struct SFloat4Modifier
		{
			EModifierOperation m_eOperation;
			SVector4 m_Value;
		};

		struct SColor3Modifier
		{
			EModifierOperation m_eOperation;
			SColorRGB m_Value;
		};

		struct SColor4Modifier
		{
			EModifierOperation m_eOperation;
			SColorRGBA m_Value;
		};

		TArrayRef<STextureModifier> m_TextureModifiers;
		TArrayRef<SFloatModifier> m_FloatModifiers;
		TArrayRef<SFloat2Modifier> m_Float2Modifiers;
		TArrayRef<SFloat3Modifier> m_Float3Modifiers;
		TArrayRef<SFloat4Modifier> m_Float4Modifiers;
		TArrayRef<SColor3Modifier> m_Color3Modifiers;
		TArrayRef<SColor4Modifier> m_Color4Modifiers;
		TArrayRef<ZResourcePtr> m_TextureResourcePtrs;

		SModifierValues(const SModifierValues& __that);
		SModifierValues() = default;
	};

	struct SModifierDefaultValues
	{
		TArray<SModifierValues::STextureModifier> m_TextureModifiers;
		TArray<SModifierValues::SFloatModifier> m_FloatModifiers;
		TArray<SModifierValues::SFloat2Modifier> m_Float2Modifiers;
		TArray<SModifierValues::SFloat3Modifier> m_Float3Modifiers;
		TArray<SModifierValues::SFloat4Modifier> m_Float4Modifiers;
		TArray<SModifierValues::SColor3Modifier> m_Color3Modifiers;
		TArray<SModifierValues::SColor4Modifier> m_Color4Modifiers;

		SModifierDefaultValues() = default;
		~SModifierDefaultValues() = default;
	};

	~IRenderMaterialEntity() override = default;
	virtual bool IsActive() const = 0;
	virtual bool IsGlobal() const = 0;
	virtual unsigned int GetModifierChangeFlag() const = 0;
	virtual void ClearModifierChangeFlag() = 0;
	virtual const SModifierDesc& GetModifierDesc() const = 0;
	virtual SModifierValues GetModifierValues() const = 0;
	virtual ZResourcePtr GetMaterialInstance() const = 0;
	virtual ZResourcePtr GetMaterialOverrideDest() const = 0;
	virtual TArray<ZEntityRef>& GetClients() = 0;
	virtual ZEntityRef GetMirror() = 0;

	static void RegisterType();
	IRenderMaterialEntity() = default;
};
